#include <sstream>
#include <queue>

#include "tree.h"

using std::queue;
using std::ostringstream;

string serialize_tree(const shared_ptr<TreeNode> &root) {
  ostringstream o_res;
  o_res << "[";

  bool b_first = true;

  // 1. frontiers
  queue<shared_ptr<TreeNode>> frontiers;
  frontiers.push(root);
  // loop
  while (!frontiers.empty()) {
    // 2. get an element
    shared_ptr<TreeNode> node = frontiers.front();
    frontiers.pop();
    // add ","
    if (b_first)
      b_first = false;
    else
      o_res << ",";
    // 3. check node
    if (node == nullptr) {
      if (b_first)
        b_first = false;
      else
        o_res << "null";
      continue;
    }
    o_res << node->val;
    // 4. add neightbors
    frontiers.push(node->left);
    frontiers.push(node->right);
  }
  o_res << "]";
  return o_res.str();
}
