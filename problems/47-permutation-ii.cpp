#include "common.h"

using namespace std;

class Solution {
public:
  void bt(const vector<int>&nums, vector<int>& cand, vector<vector<int>>& res) {
    if (nums.size() == 0) {
      res.push_back(cand);
      return;
    }

    // 1. add element
    // 2. construct new S_{k+1}
    // 3. recursive backtrack
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      auto new_nums(nums);
      new_nums.erase(new_nums.cbegin() + i);
      cand.push_back(nums[i]);
      bt(new_nums, cand, res);
      cand.pop_back();
    }
  }

  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    vector<int> init_cand;
    bt(nums, init_cand, res);
    return move(res);
  }
};

// Input: [1,1,2]
// Output:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]
int main(int argc, char *argv[])
{
  Solution s;
  vector<int> nums = {1, 1, 2, 3, 3};
  vector<int> init_cand;
  vector<vector<int>> res;
  cout << s.permuteUnique(nums) << endl;
  return 0;
}
