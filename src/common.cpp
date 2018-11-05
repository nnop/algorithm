#include "common.h"

using namespace std;

void show_tree(TreeNode *root) {
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

void show_list(ListNode *root) {
  cout << "[ ";
  for (ListNode *node = root; node != NULL; node = node->next)
    cout << node->val << " ";
  cout << "]" << endl;
}

bool operator== (const Index& lhs, const Index& rhs) {
  return lhs.value == rhs.value && lhs.index == rhs.index;
}

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> arr;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        arr.push_back(stoi(item));
    }
    return arr;
}

string integerVectorToString(vector<int>& arr, int length = -1) {
    if (length == -1) {
        length = arr.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = arr[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}
