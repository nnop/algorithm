#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
  stack<TreeNode*> frontier;
  vector<int> res;
  frontier.push(root);
  while (!frontier.empty()) {
    const TreeNode* node = frontier.top();
    frontier.pop();
    res.push_back(node->val);
    if (node->left != NULL)
      frontier.push(node->left);
    if (node->right != NULL)
      frontier.push(node->right);
  }
  return res;
}


int main(int argc, char *argv[])
{
  TreeNode node1(1), node2(2), node3(3);
  node1.right = &node2;
  node2.left = &node3;

  preorderTraversal(&node1);
  return 0;
}
