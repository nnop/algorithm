#include <memory>
#include <iostream>

#include "tree.h"

using namespace std;

int main(int argc, char *argv[])
{

  //   1
  //  / \
  // 2   3
  //    / \
  //   4   5
  auto root = make_shared<TreeNode>(1);
  root->left = make_shared<TreeNode>(2);
  root->right = make_shared<TreeNode>(3);
  root->right->left = make_shared<TreeNode>(4);
  root->right->right = make_shared<TreeNode>(5);

  cout << serialize_tree(root) << endl;
  return 0;
}
