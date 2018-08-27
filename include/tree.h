#include <string>
#include <memory>

using std::string;
using std::shared_ptr;

struct TreeNode {
  int val;
  shared_ptr<TreeNode> left;
  shared_ptr<TreeNode> right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

shared_ptr<TreeNode> deserialize_tree(const string &s_tree);

string serialize_tree(const shared_ptr<TreeNode> &root);
