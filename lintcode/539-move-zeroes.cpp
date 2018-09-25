#include "common.h"

using namespace std;

class Solution {
public:
  /**
   * @param nums: an integer array
   * @return: nothing
   */
  void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    auto p = nums.begin();
    for (int i = 0; i < n; ++i) {
      if (*p == 0) {
        p = nums.erase(p);
        nums.push_back(0);
      } else {
        ++p;
      }
    }
  }
};

int main(int argc, char *argv[])
{
  vector<int> nums = {0, 1, 0, 3, 12};
  Solution sol;
  sol.moveZeroes(nums);
  cout << nums << endl;
  return 0;
}
