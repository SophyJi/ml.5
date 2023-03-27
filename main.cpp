// Project UID db1f506d06d84ab787baf250c265e24e
#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include "csvstream.h"
#include <set>
using namespace std;

set<string> unique_words(const string &str) {
istringstream source(str);
set<string> words;
string word;
// Read word by word from the stringstream and insert into the set
while (source >> word) {
  words.insert(word);
}
return words;
}

class Classifier {
private:
    string file;
    map<string, string> row_info;
    map<string, int> count_tags;
    map<string, int> word_count;
    //For each word , the number of posts in the entire training set that
    //contain
    set<string> voca; //vocab size
    map<string, map<string, int>> label_word;
    //each label and word, the num of posts that contain the label and
    //the word,
    //string -> label, map<string -> word, int -> count
    int total = 0;
    double probability = 0.0;
public:
    Classifier(string filename) : file(filename) {}
    void read_data(bool debug){
        csvstream csvin(file, ',', true);
        set<string> all;
        while(csvin >> row_info){
            string label = row_info["tag"];
            string content = row_info["content"];
            if (debug){
                cout << "  label = " << label << ", content = "
                << content << endl;
            }
            all = unique_words(content);
            for (auto word : all){
                word_count[word] += 1;
                label_word[label][word] += 1;
            }
            voca.insert(all.begin(), all.end());
            count_tags[label] += 1;
            ++total;
    }
    }
    
    void print_training_data(){
        cout << "training data:" << endl;
    }
    
    int get_size_total() const{
        return total;
    }
    
    int get_num_uniq_word() const{
        return voca.size();
    }
    
    int get_num_tag(string tag){
        return count_tags[tag];
    }
    
    int get_word_count(string word){
        return word_count[word];
    }
    
    int get_label_word_count(string label, string word){
        return label_word[label][word];
    }
    
    double log_likelihood(string label, string word){
        if (label_word[label].find(word) != label_word[label].end()){
          return log((static_cast<double>(get_label_word_count(label, word)) /
          static_cast<double>(get_num_tag(label))));
        }else if (word_count.find(word) != word_count.end()){
            return log(static_cast<double>((get_word_count(word)) /
            static_cast<double>(get_size_total())));
        }else{
            return log(((static_cast<double>(1) /
            static_cast<double>(get_size_total()))));
        }
    }
    
    double log_prior(string label){
        return log(static_cast<double>((get_num_tag(label)) /
        static_cast<double>(get_size_total())));
    }
    
    string get_label(string str){
        set<string> post;
        map<string, double> statics;
        post = unique_words(str);
        double running_data = 0.0;
        for (auto tagg : count_tags){
            running_data += log_prior(tagg.first);
            for (auto word : post){
                running_data += log_likelihood(tagg.first, word);
            }
            statics.insert({tagg.first, running_data});
            running_data = 0.0;
        }
        double max = statics.begin() -> second;
        string label = statics.begin() -> first;
        for (auto sta : statics){
            if (sta.second > max){
                max = sta.second;
                label = sta.first;
            }
        }
        probability = max;
        return label;
    }
    
    double get_probability() const{
        return probability;
    }


    void print_class(){
        cout << "classes:" << endl;
        for (auto tagg : count_tags){
            cout << "  " << tagg.first << ", " << tagg.second
            << " examples, log-prior = " << log_prior(tagg.first) << endl;
        }
    }
    
    void print_classfier(){
        cout << "classifier parameters:" << endl;
        for (auto post : label_word){
            for (auto word : label_word[post.first]){
                cout << "  " << post.first << ":";
                cout << word.first << ", count = " << word.second
                << ", log-likelihood = "
                << log_likelihood(post.first, word.first) << endl;
            }
        }
    }
    void test_data(string filename){
    map<string, string> test;
    int count = 0;
    int correct = 0;
    csvstream csvin(filename, ',', true);
    while (csvin >> test){
        string tag = test["tag"];
        string content = test["content"];
        string predic = get_label(content);
        if (tag == predic){
            ++correct;
        }
        cout << "  correct = " << tag << ", predicted = "
        << predic;
        cout << ", log-probability score = "
        << get_probability() << endl;
        cout << "  content = " << content << endl << endl;
        ++count;
    }
    cout << "performance: " << correct << " / " << count
    << " posts predicted correctly" << endl;
}
    //read in stuff and orgnaize it in the map
    //functions that do stuff using info from maps
        //(calculations)
};



int main(int argc, char *argv[]){
    cout.precision(3);
    if (argc != 3 && argc != 4) {
        cout << "Usage: main.exe TRAIN_FILE TEST_FILE [--debug]" << endl;
    }
    Classifier c1(argv[1]);
    string testIn = argv[2];
    bool debug = false;
    if (argc > 3){
        debug = true;
    }
    if (debug){
        c1.print_training_data();
    }
    c1.read_data(debug);
    cout << "trained on " << c1.get_size_total() << " examples" << endl;
    if (debug){
    cout << "vocabulary size = " << c1.get_num_uniq_word() << endl << endl;
        c1.print_class();
        c1.print_classfier();
        cout << endl;
    }
    cout << "test data:" << endl;
    c1.test_data(testIn);
    return 0;
}
