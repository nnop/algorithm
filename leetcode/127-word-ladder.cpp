#include "common.h"

using namespace std;

typedef unordered_map<string, unordered_set<string>> Graph;

class Solution {
  public:
    int ladderLength(const string &beg, const string &end, vector<string> &word_list) {
      unordered_map<string, bool> visited;
      unordered_map<string, int> distance;
      unordered_set<string> nodes(word_list.begin(), word_list.end());
      nodes.insert(beg);
      if (nodes.find(end) == nodes.end())
        return 0;

      // create graph
      Graph graph;
      for (auto &w1 : nodes) {
        for (auto &w2 : nodes) {
          if (calc_word_dist(w1, w2) == 1) {
            graph[w1].insert(w2);
          }
        }
        visited[w1] = false;
        distance[w1] = 1;
      }

      queue<string> que;
      que.push(beg);
      while (!que.empty()) {
        string w = que.front(); que.pop();
        if (w == end)
          return distance[w];

        for (auto nb : graph[w]) {
          if (visited[nb])
            continue;

          que.push(nb);
          distance[nb] = distance[w] + 1;
          visited[nb] = true;
        }
      }
      return 0;
    }

  private:
    int calc_word_dist(const string &w1, const string &w2) {
      int d = 0, n = w1.size();
      for (int i = 0; i < n; ++i) {
        if (w1[i] != w2[i]) ++d;
      }
      return d;
    }
};

TEST_CASE("127. Word Ladder") {
  Solution sol;

  SECTION("basic") {
    string beg = "hit", end = "cog";
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log", "cog"};
    CHECK(sol.ladderLength(beg, end, word_list) == 5);
  }

  SECTION("case 1") {
    string beg = "a", end = "c";
    vector<string> word_list = {"a", "b", "c"};
    CHECK(sol.ladderLength(beg, end, word_list) == 2);
  }

  SECTION("case 2") {
    string beg = "lost", end = "cost";
    vector<string> word_list = {"most", "fist", "lost", "cost", "fish"};
    CHECK(sol.ladderLength(beg, end, word_list) == 2);
  }

  SECTION("case 3") {
    string beg = "hit", end = "cog";
    vector<string> word_list = {"hot", "dot", "dog", "lot", "log"};
    CHECK(sol.ladderLength(beg, end, word_list) == 0);
  }
}
