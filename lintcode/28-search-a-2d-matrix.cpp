#include "common.h"

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
      if (matrix.size() == 0 || matrix[0].size() == 0)
        return false;

      int M = matrix.size(), N = matrix[0].size();
      // row loop inv: [0, l] <= t, [r, n - 1] > t
      // init cond: l = -1, r = n
      // post cond: l = r - 1
      int l = -1, r = M, m;
      while (l + 1 != r) {
        m = l + (r - l) / 2;
        if (matrix[m][0] == target)
          return true;
        if (matrix[m][0] < target)
          l = m;
        else
          r = m;
      }
      if (matrix[l][0] > target)
        return false;

      // col loop inv: [0, l] <= t, [r, n - 1] > t
      // init cond: l = -1, r = n
      // post cond: l = r - 1
      int row = l;
      l = -1, r = N; 
      while (l + 1 != r) {
        m = l + (r - l) / 2;
        if (matrix[row][m] == target)
          return true;
        if (matrix[row][m] < target)
          l = m;
        else
          r = m;
      }
      return false;
    }
};

TEST_CASE("28. Search a 2D Matrix") {
  Solution sol;

  SECTION("basic") {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
      };
    CHECK(sol.searchMatrix(matrix, 1) == true);
    CHECK(sol.searchMatrix(matrix, 7) == true);
    CHECK(sol.searchMatrix(matrix, 4) == false);
    CHECK(sol.searchMatrix(matrix, 10) == true);
    CHECK(sol.searchMatrix(matrix, 23) == true);
    CHECK(sol.searchMatrix(matrix, 23) == true);
  }
}
