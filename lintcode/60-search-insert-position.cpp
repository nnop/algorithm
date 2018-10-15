#include "common.h"

using namespace std;

class Solution {
  public:
    int searchInsert(vector<int> &A, int target) {
      // loop inv: [0, l] < target && [r, n - 1] >= target
      // init cond: l = -1, r = n
      // post cond: l + 1 = r
      int l = -1, r = A.size();
      while (l + 1 != r) {
        int m = l + (r - l) / 2;
        if (A[m] < target)
          l = m;
        else
          r = m;
      }
      return r;
    }
};

TEST_CASE("60. Search Insert Position") {
  Solution sol;

  SECTION("basic") {
    vector<int> A = {1,3,5,6};
    CHECK(sol.searchInsert(A, 5) == 2);
    A = {1,3,5,6};
    CHECK(sol.searchInsert(A, 2) == 1);
    A = {1,3,5,6};
    CHECK(sol.searchInsert(A, 7) == 4);
    A = {1,3,5,6};
    CHECK(sol.searchInsert(A, 0) == 0);
  }
}
