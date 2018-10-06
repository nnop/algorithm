#include "common.h"

using namespace std;

class Solution {
public:
  Solution(const vector<bool>& stats) : stats_(stats) {}

  int findFirstBadVersion(int n) {
    int l = 1, r = n;
    // loop invariant: l <= r
    while (l < r) {
      int m = l + ((r - l) >> 1);
      if (isBadVersion(m))
        r = m;
      else
        l = m + 1;
    }
    return l;
  }

private:
  vector<bool> stats_;
  bool isBadVersion(int i) {
    assert(i > 0);
    return stats_[i - 1];
  }
};

TEST_CASE("74. First Bad Version") {
  SECTION("basic") {
    vector<bool> stats = {true, true, true, false, false};

    Solution sol(stats);
    CHECK(sol.findFirstBadVersion(stats.size() == 4));
  }
}

