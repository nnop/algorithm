// 40. Combination Sum II
#include "common.h"

using namespace std;

class Solution {
public:
  void bt(const vector<int>& nums, int target, int step,
      vector<int>& partial, vector<vector<int>>& res) {
    // check partial solution
    int sum = accumulate(partial.begin(), partial.end(), 0);
    if (sum == target) {
      res.push_back(partial);
      return;
    }

    if (sum > target || step == nums.size()) {
      return;
    }

    for (int i = step; i < nums.size(); ++i) {
      if (i > step && nums[i] == nums[i - 1])
        continue;

      // 1. extend
      partial.push_back(nums[i]);

      // 2. recursive
      bt(nums, target, i + 1, partial, res);
      partial.pop_back();
    }
  }

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> partial;
    bt(candidates, target, 0, partial, res);
    return move(res);
  }
};

// Example 1:
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
// Example 2:
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
int main(int argc, char *argv[])
{
  Solution s;
  vector<int> candidates = {10,1,2,7,6,1,5};
  int target = 8;
  cout << s.combinationSum2(candidates, target) << endl;

  return 0;
}
