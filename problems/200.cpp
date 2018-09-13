// 200. Number of Islands
#include "common.h"

using namespace std;

typedef vector<vector<char>> VVC;
typedef vector<vector<bool>> VVB;

class Solution {
private:
  int N_;
  int M_;

public:
  void fill_pool(const VVC& grid, int i, int j, VVB& visited) {
    if (i < 0 || j < 0 || i > N_-1 || j > M_-1 ||
        grid[i][j] == '0' || visited[i][j])
      return;

    visited[i][j] = true;
    fill_pool(grid, i-1, j, visited);
    fill_pool(grid, i+1, j, visited);
    fill_pool(grid, i, j-1, visited);
    fill_pool(grid, i, j+1, visited);
  }

  int numIslands(const VVC& grid) {
    // edge cases
    N_ = grid.size();
    if (N_ == 0)
      return 0;
    M_ = grid[0].size();
    if (M_ == 0)
      return 0;

    int n_pool = 0;
    VVB visited(N_, vector<bool>(M_, false));
    for (int i = 0; i < N_; ++i) {
      for (int j = 0; j < M_; ++j) {
        if (visited[i][j] || grid[i][j] == '0')
          continue;
        n_pool++;
        fill_pool(grid, i, j, visited);
      } // j
    } // i
    return n_pool;
  }
};

// Example 1:
//
// Input:
// 11110
// 11010
// 11000
// 00000
//
// Output: 1
//
// Example 2:
//
// Input:
// 11000
// 11000
// 00100
// 00011
//
// Output: 3
int main(int argc, char *argv[])
{
  vector<string> s =  {
    "11000",
    "11000",
    "00100",
    "00011"
  };

  const int N = s.size();
  const int M = s[0].length();
  vector<vector<char>> grid(N, vector<char>(M));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      grid[i][j] = s[i][j];
    }
  }

  cout << "grid: " << endl;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }

  Solution sol;
  cout << sol.numIslands(grid) << endl;

  return 0;
}
