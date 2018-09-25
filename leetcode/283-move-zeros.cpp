// 283. Move Zeroes
#include "common.h"

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int index = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums[index] = nums[i];
        ++index;
      }
    }

    for (; index < nums.size(); ++index) {
      nums[index] = 0;
    }
  }
};

// Example:
//
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Note:
//
//  - You must do this in-place without making a copy of the array.
//  - Minimize the total number of operations.
int main(int argc, char *argv[])
{
  vector<int> nums = {0,1,0,3,12};
  vector<int> ans  = {1,3,12,0,0};

  Solution sol;
  sol.moveZeroes(nums);
  check_eq(nums, ans);
  cout << "OK" << endl;
  return 0;
}
