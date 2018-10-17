// 整体思想是
#include "common.h"

using namespace std;

class Solution {
public:
  bool in_mono(vector<int> &A, int t, int l, int r) {
    if (l > r)
      return false;

    int m = l + (r - l) / 2;
    if (A[m] == t)
      return true;

    if (A[m] > t)
      return in_mono(A, t, l, m - 1);
    else
      return in_mono(A, t, m + 1, r);
  }

  bool in_range(vector<int> &A, int t, int l, int r) {
    if (l == r)
      return A[l] == t;

    if (l + 1 == r)
      return A[l] == t || A[r] == t;

    int m = l + (r - l) / 2;
    if (A[m] == t)
      return true;

    if (A[l] == A[r] && A[l] == A[m])
      return (in_range(A, t, l, m - 1) || in_range(A, t, m + 1, r));

    if (t > A[l]) { // target at left part
      if (A[m] > t)
        return in_mono(A, t, l, m - 1);
      else
        return in_range(A, t, m + 1, r);
    } else {  // target at right part
      if (A[m] < t)
        return in_mono(A, t, m + 1, r);
      else
        return in_range(A, t, l, m - 1);
    }
  }

  bool search(vector<int> &A, int target) {
    if (A.size() == 0)
      return false;

    return in_range(A, target, 0, A.size() - 1);
  }
};

TEST_CASE("63. Search in Rotated Sorted Array II") {
  Solution sol;

  SECTION("basic") {
    vector<int> A = {1, 1, 0, 1, 1, 1};
    CHECK(sol.search(A, 0) == true);
    CHECK(sol.search(A, -1) == false);
  }

  SECTION("case 1") {
    vector<int> A = {};
    CHECK(sol.search(A, 1) == false);
  }

  SECTION("case 2") {
    vector<int> A = {1};
    CHECK(sol.search(A, 0) == false);
    CHECK(sol.search(A, 1) == true);
  }

  SECTION("case 3") {
    vector<int> A = {1, 1, 2, 2, 3, 4};
    CHECK(sol.search(A, 0) == false);
    CHECK(sol.search(A, 1) == true);
    CHECK(sol.search(A, 2) == true);
  }

  SECTION("case 3") {
    vector<int> A = {9,5,6,7,8,9,9,9,9,9,9};
    CHECK(sol.search(A, 8) == true);
  }
}

