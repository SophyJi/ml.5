// Project UID db1f506d06d84ab787baf250c265e24e

#include "BinarySearchTree.h"
#include "unit_test_framework.h"

using namespace std;


TEST(test_stub) {
    // Add your tests here
    ASSERT_TRUE(true);
}
TEST(bst_test1) {
  BinarySearchTree<int> tree;

  tree.insert(10);
  tree.insert(7);

  ASSERT_TRUE(tree.size() == 2);
  ASSERT_TRUE(tree.height() == 2);
  ASSERT_TRUE(tree.find(7) == tree.begin());
  ASSERT_FALSE(tree.find(10) == tree.end());

  tree.insert(3);
 
  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 10);
  ASSERT_TRUE(*tree.min_element() == 3);
  ASSERT_TRUE(*tree.min_greater_than(8) == 10);

  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;

  cout << "cout << tree" << endl << "(uses iterators)" << endl;
  cout << tree << endl << endl;

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "10 7 3 ");
  ASSERT_TRUE(*++++tree.begin() == 10);

  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "3 7 10 ");
  BinarySearchTree<int> tree1(tree);
  cout << "cout << tree1.to_string()" << endl;
  cout << tree1.to_string() << endl << endl;
  ASSERT_TRUE(*++tree1.begin() == 7);
}
TEST(bst_test2) {
  BinarySearchTree<int> tree;
  ASSERT_TRUE(tree.size() == 0);
  tree.insert(11);       
  tree.insert(73);
  tree.insert(35);
  tree.insert(13);
  tree.insert(81);
  tree.insert(29);
  tree.insert(-8);
  tree.insert(4);
  ASSERT_TRUE(tree.size() == 8);
  ASSERT_TRUE(tree.height() == 5);
  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 81);
  ASSERT_TRUE(*tree.min_element() == -8);
  ASSERT_TRUE(tree.min_greater_than(81) == tree.end());
  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;

  cout << "cout << tree" << endl << "(uses iterators)" << endl;
  cout << tree << endl << endl;

  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "11 -8 4 73 35 13 29 81 ");

  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "-8 4 11 13 29 35 73 81 ");
//   BinarySearchTree<int>:: Iterator it1 = tree.begin();
//   ++++it1;
  BinarySearchTree<int> tree1;
  tree1.insert(10);       
  tree1.insert(73);
  tree1.insert(35);
  tree1.insert(1);
  tree1.insert(43);
  tree1.insert(77);
  ASSERT_TRUE(tree1.size() == 6);
  cout << "cout << tree1.to_string()" << endl;
  cout << tree1.to_string() << endl << endl;
  ASSERT_TRUE(tree1.find(1) == tree1.begin());
  ASSERT_TRUE(tree1.find(10) == ++tree1.begin());
  tree1 = tree;
  cout << "cout << tree1.to_string()" << endl;
  cout << tree1.to_string() << endl << endl;
  ASSERT_TRUE(tree1.size() == 8);
ASSERT_TRUE(tree1.find(-8) == tree1.begin());

}
TEST(bst_test3) {
  BinarySearchTree<int> tree;
  ASSERT_TRUE(tree.size() == 0);
  tree.insert(3); 
  ASSERT_TRUE(*tree.max_element() == 3);
  ASSERT_TRUE(*tree.min_element() == 3);
  ASSERT_TRUE(tree.min_greater_than(1) == tree.begin());
  ASSERT_TRUE(tree.min_greater_than(6) == tree.end());
  ASSERT_TRUE(tree.size() == 1);
  BinarySearchTree<int> tree1;
  tree1 = tree;
  cout << "cout << tree1.to_string()" << endl;
  cout << tree1.to_string() << endl << endl;
  ASSERT_TRUE(tree1.size() == 1);
  ASSERT_TRUE(tree1.find(3) == tree1.begin());
  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == "3 ");
  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == "3 ");
  ASSERT_TRUE(++tree.begin() == tree.end());

} 
TEST(bst_test4) {
  BinarySearchTree<int> tree;
  ASSERT_TRUE(tree.empty());
  ASSERT_TRUE(tree.max_element() == tree.begin());
  ASSERT_TRUE(tree.min_element() == tree.end());
  ASSERT_TRUE(tree.find(-7) == tree.begin());
  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;
  ASSERT_TRUE(tree.find(0) == tree.end());
  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(tree.height() == 0);
  ASSERT_TRUE(tree.min_greater_than(-100) == tree.end());
  ASSERT_TRUE(tree.max_element() == tree.end());
  ASSERT_TRUE(tree.min_element() == tree.end());
  //ASSERT_TRUE(++tree.begin() == tree.end());
  BinarySearchTree<int> tree1;
  tree1.insert(5);
  ASSERT_TRUE(tree1.size() == 1);
  tree1 = tree;
  ASSERT_TRUE(tree1.empty());
}
TEST(bst_test5){
    BinarySearchTree<int> tree;
    tree.insert(10);
    tree.insert(20);
    ASSERT_TRUE(tree.find(30) == tree.end());
    tree.insert(5);
    tree.insert(69);
    tree.insert(13);
    tree.insert(31);
    ASSERT_TRUE(tree.check_sorting_invariant());
    ASSERT_TRUE(tree.size() == 6);
    ASSERT_TRUE(tree.height() == 4);
    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(tree.max_element() == tree.find(69));
    ASSERT_TRUE(tree.min_element() == tree.find(5));
    ASSERT_TRUE(tree.min_greater_than(30) == tree.find(31));
    ASSERT_TRUE(tree.min_greater_than(70) == tree.end());
    tree.insert(80);
    tree.insert(1);
    ASSERT_TRUE(tree.check_sorting_invariant());
    ASSERT_TRUE(tree.size() == 8);
    ASSERT_TRUE(tree.height() == 4);
    ASSERT_FALSE(tree.empty());
    ASSERT_TRUE(tree.max_element() == tree.find(80));
    ASSERT_TRUE(tree.min_element() == tree.find(1));
    ASSERT_TRUE(tree.min_greater_than(70) == tree.find(80));
    ostringstream test1;
    ostringstream test2;
    tree.traverse_preorder(test1);
    tree.traverse_inorder(test2);
    ASSERT_EQUAL(test1.str(), "10 5 1 20 13 69 31 80 ");
    ASSERT_EQUAL(test2.str(), "1 5 10 13 20 31 69 80 ");
    BinarySearchTree<int> copy(tree);
    ASSERT_TRUE(copy.check_sorting_invariant());
    ASSERT_TRUE(copy.size() == 8);
    ASSERT_TRUE(copy.height() == 4);
    ASSERT_FALSE(copy.empty());
    ASSERT_TRUE(copy.max_element() == copy.find(80));
    ASSERT_TRUE(copy.min_element() == copy.find(1));
    ASSERT_TRUE(copy.min_greater_than(70) == copy.find(80));
    ostringstream test11;
    ostringstream test22;
    copy.traverse_preorder(test11);
    copy.traverse_inorder(test22);
    ASSERT_EQUAL(test11.str(), "10 5 1 20 13 69 31 80 ");
    ASSERT_EQUAL(test22.str(), "1 5 10 13 20 31 69 80 ");

    BinarySearchTree<int> copy2;
    copy2 = copy;

    ASSERT_TRUE(copy2.check_sorting_invariant());
    ASSERT_TRUE(copy2.size() == 8);
    ASSERT_TRUE(copy2.height() == 4);
    ASSERT_FALSE(copy2.empty());
    ASSERT_TRUE(copy2.max_element() == copy2.find(80));
    ASSERT_TRUE(copy2.min_element() == copy2.find(1));
    ASSERT_TRUE(copy2.min_greater_than(70) == copy2.find(80));
    ostringstream test111;
    ostringstream test222;
    copy2.traverse_preorder(test111);
    copy2.traverse_inorder(test222);
    ASSERT_EQUAL(test111.str(), "10 5 1 20 13 69 31 80 ");
    ASSERT_EQUAL(test222.str(), "1 5 10 13 20 31 69 80 ");

    BinarySearchTree<int> em;
    BinarySearchTree<int> co_em(em);
    ASSERT_TRUE(co_em.empty());
}
TEST(bst_test6) {
  BinarySearchTree<int> tree;
  ASSERT_TRUE(tree.size() == 0);
  tree.insert(10);       
  tree.insert(1);
  tree.insert(9);
  tree.insert(7);
  tree.insert(24);
  tree.insert(-2);
  tree.insert(0);
  tree.insert(-4);
  tree.insert(13);
  tree.insert(8);
  tree.insert(2);
  tree.insert(-3);
  tree.insert(18);
  tree.insert(15);
  tree.insert(25);
  tree.insert(21);
  tree.insert(34);
  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;
  ASSERT_TRUE(tree.size() == 17);
  ASSERT_TRUE(tree.height() == 5);
  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 34);
  ASSERT_TRUE(*tree.min_element() == -4);
  ASSERT_TRUE(tree.min_greater_than(-2) == tree.find(0));
  ASSERT_TRUE(tree.min_greater_than(19) == tree.find(21));
  ASSERT_TRUE(tree.min_greater_than(9) == tree.find(10));
  ostringstream oss_preorder;
  tree.traverse_preorder(oss_preorder);
  cout << "preorder" << endl;
  cout << oss_preorder.str() << endl << endl;
  ASSERT_TRUE(oss_preorder.str() == 
  "10 1 -2 -4 -3 0 9 7 2 8 24 13 18 15 21 25 34 ");
  ostringstream oss_inorder;
  tree.traverse_inorder(oss_inorder);
  cout << "inorder" << endl;
  cout << oss_inorder.str() << endl << endl;
  ASSERT_TRUE(oss_inorder.str() == 
  "-4 -3 -2 0 1 2 7 8 9 10 13 15 18 21 24 25 34 ");
  BinarySearchTree<int> tree1;
  tree1.insert(10);       
  tree1.insert(11);
  tree1.insert(19);
  tree1.insert(32);
  tree = tree1;
  ASSERT_TRUE(tree.size() == 4);
  ASSERT_TRUE(tree.height() == 4);
  ASSERT_TRUE(tree.check_sorting_invariant());
  ASSERT_TRUE(*tree.max_element() == 32);
  ASSERT_TRUE(*tree.min_element() == 10);
  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;
  ostringstream oss_preorder1;
  ostringstream oss_inorder1;
  tree.traverse_preorder(oss_preorder1);
  tree1.traverse_inorder(oss_inorder1);
  ASSERT_TRUE(oss_inorder1.str() == oss_preorder1.str());
  *tree.begin() = 27;
  *tree1.find(32) = 18;
  cout << "cout << tree.to_string()" << endl;
  cout << tree.to_string() << endl << endl;
  ASSERT_FALSE(tree.check_sorting_invariant());
  cout << "cout << tree1.to_string()" << endl;
  cout << tree1.to_string() << endl << endl;
  ASSERT_FALSE(tree1.check_sorting_invariant());
  ostringstream oss_preorder2;
  tree.traverse_preorder(oss_preorder2);
  cout << "preorder" << endl;
  cout << oss_preorder2.str() << endl << endl;
//   ASSERT_TRUE(oss_preorder.str() == 
//   "10 1 -2 -4 -3 0 9 7 2 8 24 13 18 15 21 25 34 ");
  ostringstream oss_inorder2;
  tree.traverse_inorder(oss_inorder2);
  cout << "inorder" << endl;
  cout << oss_inorder2.str() << endl << endl;
//   ASSERT_TRUE(oss_inorder.str() == 
//   "-4 -3 -2 0 1 2 7 8 9 10 13 15 18 21 24 25 34 ")


}
TEST_MAIN()
