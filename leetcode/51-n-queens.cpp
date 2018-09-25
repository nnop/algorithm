// 51. N-Queens
#include "common.h"

using namespace std;

class Solution {
public:
  vector<int> dirs = {-1, 1};

  vector<vector<string>> convert_to_strings(const vector<vector<int>>& all_res) {
    vector<vector<string>> res;
    for (const auto& indices: all_res) {
      int n = indices.size();
      vector<string> sol(n, string(n, '.'));
      for (int i = 0; i < n; ++i) {
        sol[i][indices[i]] = 'Q';
      }
      res.push_back(sol);
    }
    return res;
  }

  bool attachable(int col, const vector<int>& partial) {
    int row = partial.size();
    for (int i = 0; i < partial.size(); ++i) {
      int j = partial[i];
      if (col == j || row - col == i - j || row + col == i + j)
        return true;
    }
    return false;
  }

  void bt(int n, vector<int>& partial, vector<vector<int>>& all_res) {
    if (partial.size() == n) {
      all_res.push_back(partial);
      return;
    }

    for (int i = 0; i < n; ++i) {
      if (attachable(i, partial)) {
        continue;
      }
      partial.push_back(i);
      bt(n, partial, all_res);
      partial.pop_back();
    }
  }

  vector<vector<string>> solveNQueens(int n) {
    vector<vector<int>> all_res;
    vector<int> partial;
    bt(n, partial, all_res);
    return move(convert_to_strings(all_res));
  }
};

// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
int main(int argc, char *argv[])
{
  Solution sol;
  int n = 4;
  auto res = sol.solveNQueens(n);
  for (auto sl : res) {
    for (auto s: sl) {
      cout << s << endl;
    }
    cout << endl;
  }
  return 0;
}
