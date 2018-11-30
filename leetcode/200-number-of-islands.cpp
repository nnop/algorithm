// 200. Number of Islands
#include "common.h"

using namespace std;

vector<vector<char>> parse_input(const vector<string> &s) {
  int M = s.size();
  int N = s[0].length();
  vector<vector<char>> grid(M, vector<char>(N));

  FOR(i, M) {
    FOR(j, N) {
      grid[i][j] = s[i][j];
    }
  }
  return grid;
}

class Solution {
  public:
    int numIslands(vector<vector<char>>& grid) {
      M = grid.size();
      N = grid[0].size();

      int cnt = 0;
      FOR(i, M) {
        FOR(j, N) {
          if (grid[i][j] == '1') {
            bfs(grid, i, j);
            ++cnt;
          }
        }
      }
      return cnt;
    }

  private:
    int M, N;
    const vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>> &grid, int i, int j) {
      if (i < 0 || j < 0 || i >= M || j >= N || grid[i][j] != '1')
        return;

      grid[i][j] = '0';
      for (auto dir : dirs) {
        dfs(grid, i + dir[0], j + dir[1]);
      }
    }

    void bfs(vector<vector<char>> &grid, int i, int j) {
      queue<vector<int>> todo_nodes;
      todo_nodes.push({i, j});
      while (!todo_nodes.empty()) {
        vector<int> node = todo_nodes.front();
        todo_nodes.pop();
        i = node[0], j = node[1];
        grid[i][j] = '0';

        for (auto dir : dirs) {
          int ii = i + dir[0], jj = j + dir[1];
          if (ii < 0 || jj < 0 || ii >= M || jj >= N || grid[ii][jj] != '1')
            continue;
          todo_nodes.push({ii, jj});
        }
      }
    }
};

TEST_CASE("200. Number of Islands") {
  Solution sol;

  SECTION("case 1") {
    vector<string> input =  {
      "11110",
      "11010",
      "11000",
      "00000"
    };
    vector<vector<char>> grid = parse_input(input);
    CHECK(sol.numIslands(grid) == 1);
  }

  SECTION("case 2") {
    vector<string> input =  {
      "11000",
      "11000",
      "00100",
      "00011"
    };
    vector<vector<char>> grid = parse_input(input);
    CHECK(sol.numIslands(grid) == 3);
  }
}
