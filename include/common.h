#pragma once

#include <cassert>
#include <iostream>
#include <iomanip>
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
#include <glog/logging.h>

#define SHOW(var) std::cout << #var": " << var << std::endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = -1) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x = -1) : val(x), next(NULL) {}
};

void show_tree(TreeNode *root);

void show_list(ListNode *root);

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

template <typename T>
void check_eq(const std::vector<T>& v1, const std::vector<T>& v2) {
  CHECK_EQ(v1.size(), v2.size());
  for (int i = 0; i < v1.size(); ++i) {
    CHECK_EQ(v1[i], v2[i]) << "i=" << i;
  }
}
