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
    if (m == k - 1)
      return nums[m];
    if (m > k - 1)
      return find_num(nums, k, left, m - 1);
    return find_num(nums, k, m + 1, right);
  }

  int kthSmallest(int k, vector<int> &nums) {
    return find_num(nums, k, 0, nums.size() - 1);
  }
};

TEST_CASE("461. Kth Smallest Numbers in Unsorted Array") {
  Solution sol;

  SECTION("base") {
    vector<int> nums = {3, 4, 1, 2, 5};
    int k = 3;
    int ans = 3;
    CHECK(sol.kthSmallest(k, nums) == ans);
  }
}
