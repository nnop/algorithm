#include "common.h"

using namespace std;

int v1(vector<int> &nums, int target) {
  int n = nums.size();

  // invariant: [0, l] < t and [r, n - 1] >= t
  // init cond: l = -1, r = n, so both sets are empty.
  // post cond: l + 1 == r
  int l = -1, r = n;
  while (l + 1 < r) {
    int m = l + (r - l) / 2;
    if (nums[m] >= target)
      r = m;
    else
      l = m;
  }
  return (r < n && nums[r] == target) ? r : -1;
}

int v2(vector<int> &nums, int target) {
  int n = nums.size();

  // invariant: [0, l) < t and [r, n - 1] >= t
  // init cond: l = 0, r = n, so both sets are empty.
  // post cond: l == r
  int l = 0, r = n;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (nums[m] < target)
      l = m + 1;
    else
      r = m;
  }
  return (r < n && nums[r] == target) ? r : -1;
}

int v3(vector<int> &nums, int target) {
  int n = nums.size();

  // invariant: [0, l] < t and (r, n - 1] >= t
  // init cond: l = -1, r = n - 1, so both sets are empty.
  // post cond: l == r
  int l = -1, r = n - 1;
  while (l < r) {
    int m = l + (r - l + 1) / 2;
    if (nums[m] < target)
      l = m;
    else
      r = m - 1;
  }
  return (r < n - 1 && nums[r + 1] == target) ? r + 1 : -1;
}

int v4(vector<int> &nums, int target) {
  int n = nums.size();

  // invariant: [0, l) < t and (r, n - 1] >= t
  // init cond: l = 0, r = n - 1, so both sets are empty.
  // post cond: l == r
  int l = -1, r = n - 1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (nums[m] < target)
      l = m + 1;
    else
      r = m - 1;
  }
  return (l < n && nums[l] == target) ? l : -1;
}

class Solution {
  public:
    int binarySearch(vector<int> &nums, int target) {
      return v1(nums, target);
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

  SECTION("case 2") {
    vector<int> nums = {1, 2};
    CHECK(sol.binarySearch(nums, 1) == 0);
  }
}
