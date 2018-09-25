//561. Array Partition I
#include "common.h"

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int res = 0;
      for (int i = 0; i < nums.size(); i += 2) {
        res += nums[i];
      }
      return res;
    }
};

int main(int argc, char *argv[])
{
  vector<int> nums = {1, 4, 3, 2};
  Solution sol;
  cout << sol.arrayPairSum(nums) << endl;
  return 0;
}
