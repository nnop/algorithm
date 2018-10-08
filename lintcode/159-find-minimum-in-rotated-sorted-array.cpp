#include "common.h"

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
      int l = 0, r = nums.size() - 1;

      while (l < r) {
        int m = l + ((r - l) >> 1);
        if (nums[m] > nums[r])
          l = m + 1;
        else
          r = m;
      }

      return nums[l];
    }
};

TEST_CASE("159. Find Minimum in Rotated Sorted Array") {
  Solution sol;

  SECTION("basic") {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int ans = 0;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 1") {
    vector<int> nums = {1, 2, 3};
    int ans = 1;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 2") {
    vector<int> nums = {4,5,6,7,8,9,1,2,3};
    int ans = 1;
    CHECK(sol.findMin(nums) == ans);
  }
}

