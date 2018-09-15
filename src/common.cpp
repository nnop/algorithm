#include "common.h"

using namespace std;


void show_tree(TreeNode* root) {
  stack<pair<TreeNode*, int>> todos;
  todos.push({root, 0});
  while (!todos.empty()) {
    auto ele = todos.top();
    todos.pop();
    TreeNode* n = ele.first;
    int level = ele.second;
    if (n != NULL) {
      if (level == 0) {
        cout << ">" << n->val << endl;
      } else {
        for (int i = 0; i < level; ++i) {
          cout << " |";
        }
        cout << "-" << n->val << endl;
      }
      todos.push({n->left, level + 1});
      todos.push({n->right, level + 1});
    }
  }
}

