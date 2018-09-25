#include "common.h"
#include "catch2/catch.hpp"

using namespace std;

class Solution {
public:
  /**
   * @param nums: The integer array you should partition
   * @param k: An integer
   * @return: The index after partition
   */
  int partitionArray(vector<int> &nums, int k) {
    int n = nums.size();
    int l = 0, r = n - 1;
    while (l < r) {
      if (nums[l] < k) {
        ++l;
        continue;
      }
      if (nums[r] >= k) {
        --r;
        continue;
      }
      swap(nums[l], nums[r]);
    }
    return l;
  }
};


TEST_CASE("31. Partition Array") {
  Solution sol;

  SECTION("empty") {
    vector<int> nums = {};
    int k = 9;
    CHECK(sol.partitionArray(nums, k) == 0);
  }

  SECTION("1") {
    vector<int> nums = {3,2,2,1};
    int k = 2;
    CHECK(sol.partitionArray(nums, k) == 1);
  }

  SECTION("2") {
    vector<int> nums = {9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9};
    int k = 9;
    CHECK(sol.partitionArray(nums, k) == 10);
  }
}

