// 20. Valid Parentheses
#include "common.h"

using namespace std;

class Solution {
  public:
    bool isValid(string s) {
      stack<char> stk;
      for (auto c : s) {
        auto iter = match_map.find(c);
        if (iter != match_map.end()) {
          // left: ( [ {
          stk.push(iter->second);
        } else {
          // right: ) ] }
          if (stk.empty() || stk.top() != c)
            return false;
          stk.pop();
        }
      }

      return stk.empty();
    }

  private:
    const unordered_map<char, char> match_map = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
};

TEST_CASE("20. Valid Parentheses") {
  Solution sol;

  SECTION("basic") {
    CHECK(sol.isValid("()") == true);
    CHECK(sol.isValid("()[]{}") == true);
    CHECK(sol.isValid("(]") == false);
    CHECK(sol.isValid("([)]") == false);
    CHECK(sol.isValid("{[]}") == true);
  }

  SECTION("case 1") {
    CHECK(sol.isValid("]") == false);
  }
}
