#include "common.h"

using namespace std;

class Solution1 {
  public:
    int range_min(vector<int> &nums, int l, int r) {
      if (l + 1 >= r)
        return min(nums[l], nums[r]);

      if (nums[l] < nums[r])
        return nums[l];

      int m = l + ((r - l) >> 1);

      // condition 1: nums[l] == nums[r]
      if (nums[l] == nums[r] && nums[m] == nums[l])
        return min(range_min(nums, m + 1, r), range_min(nums, l, m - 1));

      // condition 2: nums[l] > nums[r]
      if (nums[m] > nums[r])
        return range_min(nums, m + 1, r);
      else
        return range_min(nums, l, m);
    }

    int findMin(vector<int> &nums) {
      return range_min(nums, 0, nums.size() - 1);
    }
};

class Solution2 {
  public:
    int findMin(vector<int> &nums) {
      if (nums.size() == 1)
        return nums[0];

      int l = 0, r = nums.size() - 1;

      while (l + 1 < r) {
        int m = l + ((r - l) >> 1);

        if (nums[m] == nums[r]) {
          r--;
        } else if (nums[m] < nums[r]) {
          r = m;
        } else {
          l = m + 1;
        }
      }

      return min(nums[l], nums[r]);
    }
};

TEST_CASE("160. Find Minimum in Rotated Sorted Array II") {
  Solution1 sol;

  SECTION("basic") {
    vector<int> nums = {4, 4, 5, 6, 7, 0, 1, 2};
    int ans = 0;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 1") {
    vector<int> nums = {1, 1, -1, 1};
    int ans = -1;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 2") {
    vector<int> nums = {1, 1, 1, 1};
    int ans = 1;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 3") {
    vector<int> nums = {1, 2, 1, 1};
    int ans = 1;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 4") {
    vector<int> nums = {1};
    int ans = 1;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 5") {
    vector<int> nums = {1, 2, 1};
    int ans = 1;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 6") {
    vector<int> nums = {1, 2, 2, 2, 2};
    int ans = 1;
    CHECK(sol.findMin(nums) == ans);
  }

  SECTION("case 7") {
    vector<int> nums = {0, -1, 0, 0, 0};
    int ans = -1;
    CHECK(sol.findMin(nums) == ans);
  }
}

