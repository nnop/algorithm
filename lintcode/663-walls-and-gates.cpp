// 663. Walls and Gates
#include "common.h"

using namespace std;

const vector<vector<int>> DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// BFS version
class Solution {
  public:
    void wallsAndGates(vector<vector<int>>& rooms) {
      int M = rooms.size(), N = rooms[0].size();
      queue<vector<int>> q;

      // level 0
      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if (rooms[i][j] == 0)
            q.push({i, j});
        }
      }

      // fill levels
      while (!q.empty()) {
        auto pos = q.front(); q.pop();
        int d = rooms[pos[0]][pos[1]];
        for (auto &dir : DIRS) {
          int i = pos[0] + dir[0], j = pos[1] + dir[1];
          if (i < 0 || i == M || j < 0 || j == N || rooms[i][j] <= d + 1)
            continue;
          rooms[i][j] = d + 1;
          q.push({i, j});
        }
      }
    }
};

// DFS version
class Solution2 {
  public: 
    void wallsAndGates(vector<vector<int>>& rooms) {
      M = rooms.size(), N = rooms[0].size();

      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if (rooms[i][j] == 0)
            dfs(rooms, i, j);
        }
      }
    }

  private:
    int M, N;
    void dfs(vector<vector<int>>& rooms, int pos_i, int pos_j) {
      for (auto &dir : DIRS) {
        int i = pos_i + dir[0], j = pos_j + dir[1];
        if (i < 0 || i == M || j < 0 || j == N || rooms[i][j] <= rooms[pos_i][pos_j] + 1)
          continue;
        rooms[i][j] = rooms[pos_i][pos_j] + 1;
        dfs(rooms, i, j);
      }
    }
};


TEST_CASE("663. Walls and Gates") {
  Solution2 sol;

  SECTION("case 1") {
    vector<vector<int>> rooms = {
      {INF,  -1,   0, INF},
      {INF, INF, INF,  -1},
      {INF,  -1, INF,  -1},
      {  0,  -1, INF, INF}
    };

    vector<vector<int>> ans = {
      {3, -1, 0,  1},
      {2,  2, 1, -1},
      {1, -1, 2, -1},
      {0, -1, 3,  4}
    };

    sol.wallsAndGates(rooms);
    CHECK_THAT(rooms, Equals(ans));
  }

  SECTION("case 2") {
    vector<vector<int>> rooms = {
      {INF,  -1,   0, INF},
      { -1, INF,  -1,  -1},
      {INF,  -1, INF,  -1},
      {  0,  -1, INF, INF}
    };

    vector<vector<int>> ans = {
      {INF,  -1,   0,   1},
      { -1, INF,  -1,  -1},
      {  1,  -1, INF,  -1},
      {  0,  -1, INF, INF}
    };

    sol.wallsAndGates(rooms);
    CHECK_THAT(rooms, Equals(ans));
  }
}
