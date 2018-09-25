#include <iostream>
#include <vector>

using namespace std;

int linear_access(const vector<vector<int>>& matrix, int idx) {
  int N = matrix.size(), M = matrix[0].size();
  int i = idx / M, j = idx % M;
  int value = matrix[i][j];
  return value;
}

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
  int N = matrix.size();
  if (N == 0)
    return false;
  int M = matrix[0].size();
  if (M == 0)
    return false;

  int start = 0, end = N * M - 1;
  while (start + 1 < end) {
    int mid = start + (end - start) / 2;
    int value = linear_access(matrix, mid);
    if (value < target) {
      start = mid;
    } else if (value > target) {
      end = mid;
    } else {
      end = mid;
    }
  }

  if (linear_access(matrix, start) == target || linear_access(matrix, end) == target)
    return true;
  return false;
}

int main(int argc, char *argv[])
{
  vector<vector<int>> matrix = {
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  int target = 13;
  int N = matrix.size(), M = matrix[0].size();

  cout << searchMatrix(matrix, target) << endl;

  return 0;
}
