#include "common.h"

using namespace std;

class Solution {
public:
  /**
   * @param s: A string
   * @return: Whether the string is a valid palindrome
   */
  int to_num(char c) {
    if ('a' <= c && c <= 'z')
      return c - 'a' + 10;
    if ('A' <= c && c <= 'Z')
      return c - 'A' + 10;
    if ('0' <= c && c <= '9')
      return c - '0';
    return -1;
  }

  bool isPalindrome(string &s) {
    int i = 0, j = s.length() - 1;
    // cout << "len: " << s.length() << endl;
    while (i < j) {
      int n_i = to_num(s[i]), n_j = to_num(s[j]);
      // cout << "[" << setw(2) << i << "] " << s[i] << " " << setw(2) << n_i
      //      << ", "
      //      << "[" << setw(2) << j << "] " << s[j] << " " << setw(2) << n_j << endl;
      if (n_i == -1) {
        ++i;
        continue;
      }
      if (n_j == -1) {
        --j;
        continue;
      }
      if (n_i != n_j) {
        return false;
      }
      ++i, --j;
    }
    return true;
  }
};

int main(int argc, char *argv[])
{
  string s = "1a2";
  Solution sol;
  cout << boolalpha << sol.isPalindrome(s) << endl;
  return 0;
}
