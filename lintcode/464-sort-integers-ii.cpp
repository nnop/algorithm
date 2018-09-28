#include "common.h"

using namespace std;
using Catch::Matchers::Equals;

class Solution {
public:
  /**
   * @param A: an integer array
   * @return: nothing
   */
  int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[(left + right) / 2];
    int l = left, r = right;
    while (l <= r) {
      while (l <= r && nums[l] < pivot) {
        ++l;
      }
      while (r >= l && nums[r] > pivot) {
        --r;
      }
      if (l <= r) {
        if (l != r)
          swap(nums[l], nums[r]);
        ++l, --r;
      }
    }
    return l;
  }

  void quicksort(vector<int>& nums, int left, int right) {
    if (left >= right)
      return;

    int mid = partition(nums, left, right);
    quicksort(nums, left, mid - 1);
    quicksort(nums, mid + 1, right);
  }

  void sortIntegers2(vector<int> &A) {
    quicksort(A, 0, A.size() - 1);
  }
};

class Solution2 {
public: 
  void qsort(vector<int>& nums, int left, int right) {
    int l = left, r = right;
    int val = nums[l];
    while (l < r) {
      while (r > l && nums[r] >= val)
        --r;
      nums[l] = nums[r];
      while (l < r && nums[l] <= val)
        ++l;
      nums[r] = nums[l];
    }
    nums[l] = val;
    if (l - 1 > left)
      qsort(nums, left, l - 1);
    if (l + 1 < right)
      qsort(nums, l + 1, right);
  }

  void sortIntegers2(vector<int>& nums) {
    qsort(nums, 0, nums.size() - 1);
  }
};

TEST_CASE("464. Sort Integers II") {
  Solution sol;

  SECTION("min") {
    vector<int> nums = {3, 2, 1, 4, 5};
    sol.sortIntegers2(nums);
    vector<int> ans = {1, 2, 3, 4, 5};
    CHECK_THAT(nums, Equals(ans));
  }

  SECTION("max") {
    vector<int> nums = {3, 2, 5, 4, 1};
    sol.sortIntegers2(nums);
    vector<int> ans = {1, 2, 3, 4, 5};
    CHECK_THAT(nums, Equals(ans));
  }

  SECTION("all equal") {
    vector<int> nums = {1, 1, 1, 1};
    sol.sortIntegers2(nums);
    vector<int> ans = {1, 1, 1, 1};
    CHECK_THAT(nums, Equals(ans));
  }

  SECTION("wrong 1") {
    vector<int> nums = {5, 4, 3, 2};
    sol.sortIntegers2(nums);
    vector<int> ans = {2, 3, 4, 5};
    CHECK_THAT(nums, Equals(ans));
  }
}
