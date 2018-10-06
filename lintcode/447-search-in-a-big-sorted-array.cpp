// 注意在找右区间和二分找值时 reader->get(r) == -1 的情况。

#include "common.h"

using namespace std;

class ArrayReader {
  public:
    ArrayReader(const vector<int>& arr) : arr_(arr) {}
    int get(int i) {
      if (i > arr_.size() - 1)
        return -1;
      return arr_[i];
    }

  private:
    vector<int> arr_;
};

class Solution {
  public:
    int searchBigSortedArray(ArrayReader * reader, int target) {
      int l = 0, n = 1, r = l + n - 1;
      int v = reader->get(r);
      while (v != -1 && v < target) {
        l = r + 1;
        n *= 2;
        r = l + n - 1;
        v = reader->get(r);
      };

      while (l < r) {
        int m = l + ((r - l) >> 1);
        v = reader->get(m);
        if (v >= target || v == -1)
          r = m;
        else
          l = m + 1;
      }
      return reader->get(l) == target ? l : -1;
    }
};

TEST_CASE("447. Search in a Big Sorted Array") {
  Solution sol;

  SECTION("basic") {
    vector<int> nums = {1, 3, 6, 9, 21};
    ArrayReader ar(nums);
    CHECK(sol.searchBigSortedArray(&ar, 3) == 1);
    CHECK(sol.searchBigSortedArray(&ar, 4) == -1);
  }

  SECTION("wrong 1") {
    vector<int> nums = {0, 0, 1, 1};
    ArrayReader ar(nums);
    CHECK(sol.searchBigSortedArray(&ar, 0) == 0);
  }
}

