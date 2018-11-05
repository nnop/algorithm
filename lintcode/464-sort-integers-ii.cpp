#include "common.h"

using namespace std;

int partition_lomuto(vector<int>& A, int L, int R) {
  // loop inv: [L, m] <= p
  // init cond: m = L, i = L + 1
  // post cond: i = R
  int m = L;
  for (int i = L + 1; i <= R; ++i) {
    if (A[i] < A[L])
      swap(A[i], A[++m]);
  }
  swap(A[L], A[m]);
  return m;
}

int partition1(vector<int> &A, int L, int R) {
  // pivot: A[L], process range: [L + 1, R]
  // loop inv: [L + 1, l) <= pivot && (r, R] >= pivot
  // init cond: l = L + 1, r = R, both empty sets
  // post cond: l = r + 1, A[r] == pivot
  int p = A[L];
  int l = L + 1, r = R;
  while (l <= r) {
    while (l <= r && A[l] <= p) ++l;  // post: l = r + 1 or A[l] > p
    while (l <= r && A[r] >= p) --r;  // post: l = r + 1 or A[l] < p
    if (l <= r) {
      swap(A[l], A[r]);
      ++l, --r;
    }
  } // post: l = r + 1 or r + 1 == l - 1
  swap(A[L], A[r]);
  return r;
}

int partition2(vector<int> &A, int L, int R) {
  // pivot: A[L]
  // loop inv: [L + 1, l) <= p and (r, R] >= p
  // init cond: l = L + 1, r = R
  // post cond: l == r + 1, like |r|l|
  int p = A[L];
  int l = L + 1, r = R;
  while (l < r + 1) {
    while (l < r + 1 && A[l] <= p) ++l;
    while (l < r + 1 && A[r] >= p) --r;
    if (l < r + 1) {
      swap(A[l], A[r]);
      ++l, --r;
    }
  } // post: l = r + 1
  swap(A[L], A[r]);
  return r;
}

int partition3(vector<int> &A, int L, int R) {
  // pivot: A[mid]
  // loop inv: [L + 1, l) <= p and (r, R] >= p
  int m = L + (R - L) / 2;
  swap(A[L], A[m]);
  int p = A[L];
  int l = L + 1, r = R;
  while (l <= r) {
    while (l <= r && A[l] <= p) ++l;
    while (l <= r && A[r] >= p) --r;
    if (l <= r) {
      swap(A[l], A[r]);
      ++l, --r;
    }
  }
  swap(A[L], A[r]);
  return r;
}

int partition4(vector<int> &A, int L, int R) {
  // pivot: A[L], process range: [L + 1, R]
  // loop inv: [L, l] <= pivot && [r, R] >= pivot
  // init cond: l = L, r = R + 1
  // post cond: l + 1 = r, A[l] = pivot
  int pivot = A[L];
  int l = L + 1, r = R;
  while (l + 1 < r) {
    while (l + 1 < r && A[l] <= pivot) ++l;
    while (l + 1 < r && A[r] >= pivot) --r;
    if (l + 1 < r) {
      swap(A[l], A[r]);
      ++l, --r;
    }
  }

  int m = l;
  if (l == r) { // l == r
    if (A[l] > pivot)
      m = l - 1;
  } else {      // l + 1 == r
    if (A[l] > pivot && A[r] < pivot) {
      swap(A[l], A[r]);
    } else if (A[l] > pivot && A[r] >= pivot) {
      m = l - 1;
    } else if (A[r] < pivot && A[l] <= pivot) {
      m = l + 1;
    }
  }

  swap(A[L], A[m]);
  return m;
}

class Solution {
  public:
    void sortIntegers2(vector<int> &A) {
      quicksort(A, 0, A.size() - 1);
    }

  private:
    int iter_;

    void quicksort(vector<int> &A, int l, int r) {
      if (l >= r)
        return;

      int m = partition3(A, l, r);
      quicksort(A, l, m - 1);
      quicksort(A, m + 1, r);
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
