#include <vector>
#include <iostream>

using namespace std;

int binary_search(const vector<int>& nums, int target, bool b_first) {
    int start = 0, end = nums.size() - 1;
    while (start + 1 < end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] < target) {
            start = mid;
        } else if (nums[mid] > target) {
            end = mid;
        } else {   // ==
            if (b_first)
                end = mid;
            else
                start = mid;
        }
        cout << "mid: " << mid << " start/end: (" << start << ", " << end << ")" << endl;
    }
    if (b_first) {
        cout << "a" << endl;
        if (nums[start] == target)
            return start;
        if (nums[end] == target)
            return end;
        return -1;
    } else {
        cout << "b" << endl;
        if (nums[end] == target)
            return end;
        if (nums[start] == target)
            return start;
        return -1;
    }
}

int main(int argc, char *argv[])
{
  vector<int> nums = {5,7,7,8,8,10};
  int target = 8;
  cout << binary_search(nums, target, false) << endl;
  return 0;
}
