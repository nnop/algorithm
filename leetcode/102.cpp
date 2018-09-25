// 102. Binary Tree Level Order Traversal

#include <utility>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

#include "tree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      int level = 0;
      // {node, level}
      queue<pair<TreeNode*, int>> todos;
      todos.push({root, 0});
      while (!todos.empty()) {
        TreeNode* n = todos.front().first;
        int l = todos.front().second;
        todos.pop();
        if (n == NULL)
          continue;
        if (res.size() < l + 1)
          res.resize(l + 1);
        res[l].push_back(n->val);
        todos.push({n->left, l + 1});
        todos.push({n->right, l + 1});
      }
      return std::move(res);
    }
};

// Given binary tree [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7
// return its level order traversal as:
// [
//   [3],
//   [9,20],
//   [15,7]
// ]
int main(int argc, char *argv[])
{
  // define nodes
  unordered_map<int, TreeNode> nodes;
  nodes[3] = 3;
  nodes[9] = 9;
  nodes[20] = 20;
  nodes[15] = 15;
  nodes[7] = 7;

  // construct tree
  TreeNode* root = &nodes[3];
  nodes[3].left = &nodes[9];
  nodes[3].right = &nodes[20];
  nodes[20].left = &nodes[15];
  nodes[20].right = &nodes[7];

  Solution s;
  auto res = s.levelOrder(root);
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res[i].size(); ++j) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
