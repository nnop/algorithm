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
    bt(nums, step + 1, extend, res);

    extend.push_back(nums[step]);
    bt(nums, step + 1, extend, res);
  }

  vector<vector<int>> subsets(const vector<int>& nums) {
    vector<vector<int>> res;
    bt(nums, 0, {}, res);
    return std::move(res);
  }
};

// Input: nums = [1,2,3]
// Output:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]
int main(int argc, char *argv[])
{
  vector<int> nums = {1, 2, 3};
  Solution s;
  auto res = s.subsets(nums);
  cout << "-- res --" << endl;
  cout << res << endl;
  return 0;
}
