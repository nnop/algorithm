#include "common.h"

using namespace std;

class Solution {
  public:
    bool search(vector<int>& nums, int target) {
      int n = nums.size();
      if (n == 0)
        return false;

      int pivot = nums[0];
      if (pivot == target)
        return true;

      int l = 0, r = n - 1;
      while (l <= r) {
        int m = l + (r - l) / 2;

        if (nums[m] == target)
          return true;

        if (nums[m] == pivot) {
          if (nums[l] == pivot)
            ++l;
          if (nums[r] == pivot)
            --r;
          continue;
        }

        if (target > pivot) {
          if (nums[m] > target)
            r = m - 1;
          else if (nums[m] > pivot)
            l = m + 1;
          else
            r = m - 1;
        }

        if (target < pivot) {
          if (nums[m] < target)
            l = m + 1;
          else if (nums[m] > pivot)
            l = m + 1;
          else
            r = m - 1;
        }      
      }

      return false;
    }
};

TEST_CASE("81. Search in Rotated Sorted Array II") {
  Solution sol;

  SECTION("case 1") {
    vector<int> nums = {3, 1};
    CHECK(sol.search(nums, 1) == true);
    CHECK(sol.search(nums, 3) == true);
  }

  SECTION("case 2") {
    vector<int> nums = {1, 3, 1, 1, 1};
    CHECK(sol.search(nums, 3) == true);
  }

  SECTION("case 3") {
    vector<int> nums = {1, 3};
    CHECK(sol.search(nums, 1) == true);
    CHECK(sol.search(nums, 3) == true);
  }

  SECTION("case 4") {
    vector<int> nums = {1, 1, 3, 1};
    CHECK(sol.search(nums, 3) == true);
  }
}
