#include "common.h"

using namespace std;

class Solution {
public:
  int partition(vector<int>& nums, int left, int right) {
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

    int m = partition(nums, left, right);
    if (m == k)
      return nums[m];
    if (m > k)
      return find_num(nums, k, left, m - 1);
    return find_num(nums, k, m + 1, right);
  }

  int findKthLargest(vector<int>& nums, int k) {
    return find_num(nums, nums.size() - k, 0, nums.size() - 1);
  }
};

TEST_CASE("215. Kth Largest Element in an Array") {
  Solution sol;

  SECTION("basic 1") {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    int ans = 5;
    CHECK(sol.findKthLargest(nums, k) == ans);
  }

  SECTION("basic 2") {
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    int ans = 4;
    CHECK(sol.findKthLargest(nums, k) == ans);
  }
}
