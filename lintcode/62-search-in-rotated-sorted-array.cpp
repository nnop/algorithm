#include "common.h"

using namespace std;

class Solution {
public:
  int search(vector<int> &A, int target) {
    if (A.size() == 0)
      return -1;

    int l = 0, r = A.size() - 1, pvt = A[0];

    while (l <= r) {
      int m = l + (r - l) / 2;
      if (A[m] == target)
        return m;

      if (target >= pvt) {
        if (A[m] < pvt || A[m] > target)
          r = m - 1;
        else
          l = m + 1;
      } else {
        if (A[m] < pvt && A[m] > target)
          r = m - 1;
        else
          l = m + 1;
      }
    }

    return -1;
  }
};

TEST_CASE("62. Search in Rotated Sorted Array") {
  Solution sol;

  SECTION("basic") {
    vector<int> A = {4, 5, 1, 2, 3};
    int target = 1;
    int ans = 2;
    CHECK(sol.search(A, target) == ans);
  }

  SECTION("case 1") {
    vector<int> A = {4, 3};
    int target = 3;
    int ans = 1;
    CHECK(sol.search(A, target) == ans);
  }

  SECTION("case 2") {
    vector<int> A = {6,8,9,1,3,5};
    int target = 5;
    int ans = 5;
    CHECK(sol.search(A, target) == ans);
  }
}

