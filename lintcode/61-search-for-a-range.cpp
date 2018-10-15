#include "common.h"

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &A, int target) {
      arr_ = A;
      t_ = target;

      int l = -1, r = A.size(), m1 = -1, m2 = -1;
      search_all(l, r, m1, m2);

      return {m1, m2};
    }

  private:
    void search_left(int l, int &mr) {
#ifdef DEBUG
      cout << "L: l = " << l << ", mr = " << mr << endl;
#endif
      if (l + 1 == mr)
        return;

      int m = l + (mr - l) / 2;
      if (arr_[m] == t_)
        mr = m;
      else
        l = m;
      search_left(l, mr);
    }

    void search_right(int r, int &ml) {
#ifdef DEBUG
      cout << "R: r = " << r << ", ml = " << ml << endl;
#endif
      if (ml + 1 == r)
        return;

      int m = ml + (r - ml) / 2;
      if (arr_[m] == t_)
        ml = m;
      else
        r = m;
      search_right(r, ml);
    }

    void search_all(int l, int r, int &m1, int &m2) {
      // loop inv: [0, l] < t && [m1, m2] == t && [r, n - 1] > t
      // init cond: l = -1, r = n
      // post cond: l + 1 = r
#ifdef DEBUG
      cout << "A: l = " << l << ", r = " << r
        << ", m1 = " << m1 << ", m2 = " << m2 << endl;
#endif
      if (l + 1 == r) {
        m1 = -1;
        m2 = -1;
        return;
      }

      int m = l + (r - l) / 2;
      if (arr_[m] == t_) {
        m1 = m;
        m2 = m;
        search_left(l, m1);
        search_right(r, m2);
      } else if (arr_[m] < t_) {
        search_all(m, r, m1, m2);
      } else {
        search_all(l, m, m1, m2);
      }
    }


    vector<int> arr_;
    int t_;
};

TEST_CASE("61. Search for a Range") {
  Solution sol;

  SECTION("basic") {
    //               0  1  2  3  4  5
    vector<int> A = {5, 7, 7, 8, 8, 10};
    vector<int> ans = {3, 4};
    CHECK_THAT(sol.searchRange(A, 8), Equals(ans));
    ans = {0, 0};
    CHECK_THAT(sol.searchRange(A, 5), Equals(ans));
    ans = {1, 2};
    CHECK_THAT(sol.searchRange(A, 7), Equals(ans));
    ans = {-1, -1};
    CHECK_THAT(sol.searchRange(A, 9), Equals(ans));
  }
}
