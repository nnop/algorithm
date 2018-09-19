#include "common.h"

using namespace std;

class Solution {
public:
  void bt(const vector<int>& candidates, int target,
      vector<int>& partial, vector<vector<int>>& res) {
    int sum = accumulate(partial.begin(), partial.end(), 0);
    if (sum >= target) {
      if (sum == target)
        res.push_back(partial);
      return;
    }

    // 1. extend
    // 2. candidates
    // 3. recursive
    for (int i = 0; i < candidates.size(); ++i) {
      partial.push_back(candidates[i]);
      vector<int> new_cands;
      new_cands.insert(new_cands.end(), candidates.begin() + i, candidates.end());
      bt(new_cands, target, partial, res);
      partial.pop_back();
    }
  }

  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> partial;
    bt(candidates, target, partial, res);
    return move(res);
  }
};

// Example 1:
//
// Input: candidates = [2,3,6,7], target = 7,
// A solution set is:
// [
//   [7],
//   [2,2,3]
// ]
// Example 2:
//
// Input: candidates = [2,3,5], target = 8,
// A solution set is:
// [
//   [2,2,2,2],
//   [2,3,3],
//   [3,5]
// ]
int main(int argc, char *argv[])
{
  Solution s;
  vector<int> candidates = {2, 3, 5};
  int target = 8;
  cout << s.combinationSum(candidates, target) << endl;
  return 0;
}
