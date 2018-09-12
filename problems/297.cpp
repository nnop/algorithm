// 297. Serialize and Deserialize Binary Tree
//
// Solution: BFS
//
// You may serialize the following tree:
//
//     1
//    / \
//   2   3
//      / \
//     4   5
//
// as "[1,2,3,null,null,4,5]"

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <vector>

#include "tree.h"

using namespace std;

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
      vector<string> elements;
      queue<TreeNode*> todos;
      todos.push(root);

      while (! todos.empty()) {
        TreeNode* n = todos.front();
        todos.pop();
        if (n == NULL) {
          elements.push_back("null");
          continue;
        } else {
          elements.push_back(to_string(n->val));
        }
        todos.push(n->left);
        todos.push(n->right);
      }

      // remove trailing nulls
      int n = elements.size() - 1;
      if (elements[n] == "null") {
        for (; n >= 0; --n) {
          if (elements[n] != "null")
            break;
        }
      }
      elements.resize(n + 1);
      
      // format result
      string res;
      for (auto s : elements) {
        res += s;
        res += " ";
        cout << res << endl;
      }
      return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    }
};


int main(int argc, char *argv[])
{
  // define nodes
  unordered_map<int, TreeNode> nodes;
  for (int i = 1; i < 6; ++i) {
    nodes[i] = i;
  }

  // construct tree
  TreeNode* root = &nodes[1];
  nodes[1].left = &nodes[2];
  nodes[1].right = &nodes[3];
  nodes[3].left = &nodes[4];
  nodes[3].right = &nodes[5];

  Codec cc;
  cout << cc.serialize(root) << endl;

  return 0;
}

