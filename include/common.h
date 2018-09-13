#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stack>
#include <queue>

#define SHOW(var) std::cout << #var": " << var << std::endl

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = -1) : val(x), left(NULL), right(NULL) {}
};


void show_tree(TreeNode* root);

