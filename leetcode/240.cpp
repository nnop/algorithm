#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if (matrix.size() == 0 || matrix[0].size() == 0)
    return false;
  int M = matrix.size(), N = matrix[0].size();
  int i = 0, j = N - 1;
  while (i < M && j >= 0) {
    if (target > matrix[i][j])
      ++i;
    else if (target < matrix[i][j])
      --j;
    else
      return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  vector<vector<int>> matrix = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  };
  cout << searchMatrix(matrix, 18) << endl;
  return 0;
}
