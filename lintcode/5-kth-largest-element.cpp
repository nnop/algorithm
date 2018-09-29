#include "common.h"

using namespace std;

class Solution {
public:
  int partition_hoare(vector<int>& nums, int left, int right) {
    int idx = (left + right) / 2;
    int pivot = nums[idx];
    swap(nums[right], nums[idx]);
    int l = left, r = right - 1;
    while (l <= r) {
      while (l <= r && nums[l] < pivot)
        ++l;
      while (l <= r && nums[r] > pivot)
        --r;
      if (l <= r) {
        if (l < r)
          swap(nums[l], nums[r]);
        ++l, --r;
      }
    }
    swap(nums[l], nums[right]);
    return l;
  }

  int partition_lomuto(vector<int>& nums, int left, int right) {
    int m = left;
    for (int i = left + 1; i <= right; ++i) {
      if (nums[i] < nums[left])
        swap(nums[i], nums[++m]);
    }
    swap(nums[left], nums[m]);
    return m;
  }

  int find_num(vector<int>& nums, int k, int left, int right) {
    if (left >= right)
      return nums[left];

    int mid = partition_lomuto(nums, left, right);
    if (mid == k)
      return nums[mid];
    if (mid < k)
      return find_num(nums, k, mid + 1, right);
    return find_num(nums, k, left, mid - 1);
  }

  int kthLargestElement(int k, vector<int> &nums) {
    return find_num(nums, nums.size() - k, 0, nums.size() - 1);
  }
};


TEST_CASE("5. Kth Largest Element") {
  Solution sol;

  SECTION("basic") {
    vector<int> nums = {9, 3, 2, 4, 8};
    int k = 3;
    int ans = 4;
    CHECK(sol.kthLargestElement(k, nums) == ans);
  }

  SECTION("wrong 1") {
    vector<int> nums = {1, 3, 4, 2};
    int k = 1;
    int ans = 4;
    CHECK(sol.kthLargestElement(k, nums) == ans);
  }
}
