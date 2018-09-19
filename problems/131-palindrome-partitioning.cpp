// 131. Palindrome Partitioning
#include "common.h"

using namespace std;

class Solution {
public:
  bool is_palindrome(string s) {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
      if (s[i] != s[j])
        return false;
    }
    return true;
  }

  vector<vector<string>> convert_to_strings(const string& ori_s,
      const vector<vector<int>>& all_cuts) {
    vector<vector<string>> res;
    for (const auto& cuts: all_cuts) {
      vector<string> v_s;
      for (int i = 1; i < cuts.size(); ++i) {
        v_s.push_back(ori_s.substr(cuts[i - 1], cuts[i] - cuts[i - 1]));
      }
      res.push_back(v_s);
    }
    return move(res);
  }

  // Args:
  //  partial: cut indices
  void bt(const string& ori_s, int step,
      vector<int>& partial, vector<vector<int>>& all_cuts) {
    // return condition
    if (step == ori_s.length() + 1) {
      all_cuts.push_back(partial);
      return;
    }

    int i_prev = partial.back();
    for (int i = step; i < ori_s.length() + 1; ++i) {
      // extend
      string sub_s = ori_s.substr(i_prev, i - i_prev);
      if (!is_palindrome(sub_s))
        continue;

      partial.push_back(i);
      bt(ori_s, i + 1, partial, all_cuts);
      partial.pop_back();
    }
  }

  vector<vector<string>> partition(string ori_s) {
    vector<vector<int>> all_cuts;
    vector<int> partial(1, 0);
    bt(ori_s, 1, partial, all_cuts);

    return convert_to_strings(ori_s, all_cuts);
  }
};

// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
int main(int argc, char *argv[])
{
  Solution sol;
  string s = "aab";
  cout << sol.partition(s) << endl;
  return 0;
}
