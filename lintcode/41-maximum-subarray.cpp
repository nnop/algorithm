#include "common.h"

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int opt_pre = 0, opt_cur = 0, opt_all = numeric_limits<int>::min();
    for (int i = 0; i < nums.size(); ++i) {
      opt_cur = opt_pre > 0 ? nums[i] + opt_pre : nums[i];
      opt_all = opt_all > opt_cur ? opt_all : opt_cur;
      opt_pre = opt_cur;
    }
    return opt_all;
  }
};

TEST_CASE("41. Maximum Subarray") {
  Solution sol;

  SECTION("basic") {
    vector<int> nums = {-2,2,-3,4,-1,2,1,-5,3};
    int ans = 6;
    CHECK(sol.maxSubArray(nums) == ans);
  }
}
