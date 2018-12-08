#include "common.h"

using namespace std;

const vector<vector<int>> DIRS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

class Solution {
  public:
    void solve(vector<vector<char>>& board) {
      M = board.size();
      if (M == 0) return;
      N = board[0].size();
      if (N == 0) return;

      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if ((i == 0 || i == M - 1 || j == 0 || j == N - 1) && board[i][j] == 'O')
            dfs(board, i, j);
        }
      }

      for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
          if (board[i][j] == 'O')
            board[i][j] = 'X';
          else if (board[i][j] == '$')
            board[i][j] = 'O';
        }
      }
    }

  private:
    int M, N;

    void dfs(vector<vector<char>> &board, int pos_i, int pos_j) {
      board[pos_i][pos_j] = '$';
      for (auto &dir : DIRS) {
        int i = pos_i + dir[0], j = pos_j + dir[1];
        if (i < 0 || i == M || j < 0 || j == N || board[i][j] != 'O')
          continue;
        dfs(board, i, j);
      }
    }
};

vector<vector<char>> convert(vector<string> &input) {
  vector<vector<char>> vc(input.size());
  for (int i = 0; i < input.size(); ++i) {
    for (auto &c : input[i]) {
      vc[i].push_back(c);
    }
  }
  return vc;
}

TEST_CASE("130. Surrounded Regions") {
  Solution sol;

  SECTION("basic") {
    vector<string> input =  {
      "XXXX",
      "XOOX",
      "XXOX",
      "XOXX"
    };
    vector<string> output = {
      "XXXX",
      "XXXX",
      "XXXX",
      "XOXX"
    };

    vector<vector<char>> board = convert(input);
    vector<vector<char>> ans = convert(output);
    sol.solve(board);
    CHECK_THAT(ans, Equals(board));
  }
}
