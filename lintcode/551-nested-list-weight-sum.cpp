#include "common.h"

using namespace std;

typedef vector<int> VI;

class NestedInteger {
  public:
    NestedInteger() : is_int_(false), i_(0) {}
    NestedInteger(int i) : is_int_(true), i_(i) {}
    NestedInteger(const vector<NestedInteger> &v) : is_int_(false), i_(0), v_(v) {}

    bool isInteger() const { return is_int_; }
    int getInteger() const { return i_; }
    const vector<NestedInteger> &getList() const { return v_; }

  private:
    bool is_int_;
    int i_;
    vector<NestedInteger> v_;
};

typedef vector<NestedInteger> VNI;

class Solution {
  public:
    int depthSum(const vector<NestedInteger>& nestedList) {
      return dfs(nestedList, 1);
    }

  private:
    int dfs(const vector<NestedInteger> &v_ni, int level) {
      int sum = 0;
      for (const auto &ni : v_ni) {
        if (ni.isInteger())
          sum += level * ni.getInteger();
        else
          sum += dfs(ni.getList(), level + 1);
      }
      return sum;
    }
};

TEST_CASE("551. Nested List Weight Sum") {
  Solution sol;

  SECTION("basic") {
    CHECK(sol.depthSum({VNI{1, 1}, 2, VNI{1, 1}}) == 10);
    CHECK(sol.depthSum({1, VNI{4, VNI{6}}}) == 27);
  }
}
