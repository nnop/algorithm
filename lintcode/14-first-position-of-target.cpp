#include "common.h"

using namespace std;

class Solution {
  public:
    int binarySearch(vector<int> &nums, int target) {
      if (nums.size() == 0)
        return -1;

      int l = 0, r = nums.size() - 1;
      // loop invariant: A[l] <= t && A[r] >= t
      while (l < r) {
        int m = l + ((r - l) >> 1);
        // move towards left
        if (nums[m] >= target)
          r = m;
        else
          l = m + 1;
      }
      // post condition: l == r
      return (nums[l] == target) ? l : -1;
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

  SECTION("1") {
    vector<int> nums = {1, 2, 3};
    int target = 2;
    int ans = 1;
    CHECK(sol.binarySearch(nums, target) == ans);
  }
}
