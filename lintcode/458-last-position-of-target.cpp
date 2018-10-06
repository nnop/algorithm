#include "common.h"

using namespace std;

class Solution {
  public:
    int lastPosition(vector<int> &nums, int target) {
      if (nums.size() == 0)
        return -1;

      int l = 0, r = nums.size() - 1;
      // loop invariant: A[l] <= t && A[r] >= t
      while (l < r) {
        int m = l + ((r - l + 1) >> 1);
        // move towards right
        if (nums[m] <= target)
          l = m;
        else
          r = m - 1;
      }
      // post condition: l == r
      return (nums[l] == target) ? l : -1;
    }
};

TEST_CASE("458. Last Position of Target") {
  Solution sol;

  SECTION("basic") {
    vector<int> nums = {1, 2, 2, 4, 5, 5};
    CHECK(sol.lastPosition(nums, 2) == 2);
    CHECK(sol.lastPosition(nums, 5) == 5);
    CHECK(sol.lastPosition(nums, 6) == -1);
  }

  SECTION("2") {
    vector<int> nums = {1, 2, 3};
    int target = 2;
    int ans = 1;
    CHECK(sol.lastPosition(nums, target) == ans);
  }
}
