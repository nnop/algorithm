#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
  if (nums.size() == 0)
    return -1;

  int start = 0, end = nums.size() - 1;
  if (nums[0] == target)
    return 0;

  while (start + 1 < end) {
    int mid = start + (end - start) / 2;
    if (target < nums[0]) {
      if (nums[mid] < target || nums[mid] > nums[0])
        start = mid;
      else if (nums[mid] > target && nums[mid] < nums[0])
        end = mid;
      else
        return mid;
    } else {
      if (nums[mid] < target && nums[mid] > nums[0])
        start = mid;
      else if (nums[mid] > target || nums[mid] < nums[0])
        end = mid;
      else
        return mid;
    }
  } // while

  if (nums[start] == target)
    return start;
  if (nums[end] == target)
    return end;
  return -1;
}

int main(int argc, char *argv[])
{
  vector<int> nums = {4,5,6,7,0,1,2};
  int target = 7;
  cout << search(nums, target) << endl;
  return 0;
}
