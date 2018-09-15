// 78. Subsets
#include "common.h"

using namespace std;

class Solution {
public:
  void add_set(vector<int> nums, int pos, vector<vector<int>>& res) {
    if (pos == -1) {
      res.push_back(nums);
      return;
    }
    add_set(nums, pos - 1, res);
    nums.erase(nums.cbegin() + pos);
    add_set(nums, pos - 1, res);
  }

  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    add_set(nums, nums.size() - 1, res);
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
