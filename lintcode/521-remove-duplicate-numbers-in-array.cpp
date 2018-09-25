#include "common.h"

using namespace std;

class Solution {
public:
  /**
   * @param nums: an array of integers
   * @return: the number of unique integers
   */
  int deduplication(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    sort(nums.begin(), nums.end());
    int index = 0;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] != nums[i - 1]) {
        nums[++index] = nums[i];
      }
    }
    return index + 1;
  }
};

int main(int argc, char *argv[])
{
  vector<int> nums = {1,3,1,4,4,2};
  
  Solution sol;
  cout << sol.deduplication(nums) << endl;
  cout << nums << endl;
  return 0;
}
