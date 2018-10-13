#include "common.h"

using namespace std;

class Solution {
  public:
    int binarySearch(vector<int> &nums, int target) {
      if (nums.size() == 0)
        return -1;

      // invariant: [0, l) < t && (r, n - 1] >= t
      // init cond: l = 0, r = n - 1, so both sets are empty.
      // post cond: l == r
      int l = 0, r = nums.size() - 1;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] >= target)
          r = m;
        else
          l = m + 1;
      }
      return nums[l] == target ? l : -1;
    }
};

TEST_CASE("14. First Position of Target") {
  Solution sol;

  SECTION("basic") {
    vector<int> nums = {1, 2, 3, 3, 4, 5, 10};
    int target = 3;
    int ans = 2;
    CHECK(sol.binarySearch(nums, target) == ans);
  }

  SECTION("case 1") {
    vector<int> nums = {1, 2, 3};
    CHECK(sol.binarySearch(nums, 0) == -1);
    CHECK(sol.binarySearch(nums, 1) == 0);
    CHECK(sol.binarySearch(nums, 2) == 1);
    CHECK(sol.binarySearch(nums, 3) == 2);
    CHECK(sol.binarySearch(nums, 4) == -1);
  }
}
