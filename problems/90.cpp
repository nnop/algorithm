// 78. Subsets
#include "common.h"

using namespace std;

class Solution {
public:
  void bt(const vector<int>& nums, int step, const vector<int>& cand,
      vector<vector<int>>& res) {
    if (step == nums.size()) {
      res.push_back(cand);
      return;
    }

    vector<int> extend(cand);
    int i_next = step + 1;
    for (; i_next < nums.size() && nums[i_next] == nums[step]; ++i_next);
    bt(nums, i_next, extend, res);

    extend.push_back(nums[step]);
    bt(nums, step + 1, extend, res);
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    bt(nums, 0, {}, res);
    return std::move(res);
  }
};

// Input: [1,2,2]
// Output:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]
int main(int argc, char *argv[])
{
  vector<int> nums = {1, 2, 2};
  Solution s;
  auto res = s.subsetsWithDup(nums);
  cout << "-- res --" << endl;
  cout << res << endl;
  return 0;
}
