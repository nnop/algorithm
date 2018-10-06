#include "common.h"

using namespace std;

class Solution {
  public:
    int findPosition(vector<int> &nums, int target) {
      if (nums.size() == 0)
        return -1;

      int l = 0, r = nums.size() - 1;
      // loop invariant: range [l, r] contains t
      while (l <= r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] == target)
          return m;

        if (nums[m] < target)
          l = m + 1;
        else
          r = m - 1;  
      }
      return -1;
    }
};

TEST_CASE("457. Classic Binary Search") {
  Solution sol;

  SECTION("basic") {
    vector<int> nums = {1, 2, 2, 4, 5, 5};
    int target = 2;
    vector<int> ans = {1, 2};
    CHECK_THAT(ans, VectorContains(sol.findPosition(nums, target)));
  }
}
