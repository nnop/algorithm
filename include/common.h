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
#include <limits>
#include <functional>
#include <glog/logging.h>

#include "catch2/catch.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::Contains;
using Catch::Matchers::VectorContains;

#define SHOW(var) std::cout << #var": " << var << std::endl

#define FROM(i, m, n) for (int(i) = (m); (i) < (n); ++(i))
#define MORF(i, m, n) for (int(i) = (n) - 1; (i) >= (m); --(i))
#define FOR(i, n) for (int(i) = 0; (i) < (n); ++(i))
#define ROF(i, n) for (int(i) = (n) - 1; (i) >= 0; --(i))
#define FOREACH(i, n) for (auto i = (n).begin(); i != (n).end(); ++i)

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

struct Index {
  int value;
  int index;
  Index(int val, int idx = 0) : value(val), index(idx) {}
};

// make pair<T, R> hashable
template<typename T, typename R>
struct std::hash<std::pair<T, R>> {
  size_t operator() (const std::pair<T, R>& s) const {
    size_t h1 = std::hash<T>{}(s.first);
    size_t h2 = std::hash<R>{}(s.second);
    return h1 ^ (h2 << 1);
  }
};

// make Index hashable
template<> struct std::hash<Index> {
  size_t operator() (const Index& idx) const {
    size_t h1 = std::hash<int>{}(idx.value);
    size_t h2 = std::hash<int>{}(idx.index);
    return h1 ^ (h2 << 1);
  }
};

bool operator== (const Index& lhs, const Index& rhs);

//
// print functions
//
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

//
// check functions
//
template <typename T>
void check_eq(const std::vector<T>& v1, const std::vector<T>& v2) {
  CHECK_EQ(v1.size(), v2.size());
  for (int i = 0; i < v1.size(); ++i) {
    CHECK_EQ(v1[i], v2[i]) << "i=" << i;
  }
}

//
// node pool
//
template <typename T>
void create_node_pool(const std::vector<int>& nums, std::unordered_map<Index, T>& nodes) {
  std::unordered_map<int, int> nums_map;
  for (auto i : nums) {
    if (nums_map.find(i) == nums_map.end())
      nums_map[i] = 0;
    else
      nums_map[i] += 1;
    nodes[{i, nums_map[i]}] = T(i);
  }
}

template <typename T>
void show_node_pool(const std::unordered_map<Index, T>& nodes) {
  for (const auto & elem : nodes) {
    std::cout << "index: (" << elem.first.value << ", " << elem.first.index
         << "), node: " << elem.second.val << std::endl;
  }
}
