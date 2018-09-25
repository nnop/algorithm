#include "common.h"

using namespace std;

class Solution {
public:
  void bt(const vector<int>& nums, vector<int>& cand, vector<vector<int>>& res) {
    if (nums.size() == 0) {
      res.push_back(cand);
      return;
    }

    // 1. add an element
    // 2. construct new S_(k+1)
    // 3. recursive backtrack
    for (int i = 0; i < nums.size(); ++i) {
      cand.push_back(nums[i]);
      vector<int> new_nums(nums);
      new_nums.erase(new_nums.cbegin() + i);
      bt(new_nums, cand, res);
      cand.pop_back();
    }
  }

  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> init_cand;
    bt(nums, init_cand, res);
    return std::move(res);
  }
};

// Input: [1,2,3]
// Output:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]
int main(int argc, char *argv[])
{
  vector<int> nums = {1, 2, 3};

  Solution s;
  cout << s.permute(nums) << endl;
  return 0;
}
