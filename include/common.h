#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>

#define SHOW(var) std::cout << #var": " << var << std::endl

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = -1) : val(x), left(NULL), right(NULL) {}
};


void show_tree(TreeNode* root);

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& arr) {
  os << "[ ";
  for (auto i : arr) {
    os << i << " ";
  }
  os << "]";
  return os;
}

template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<std::vector<T>>& arr_set) {
  for (const auto& arr : arr_set) {
    os << arr << std::endl;
  }
  return os;
}
