#include "catch.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::min;

class Solution {
public:
  int minDistance(string word1, string word2) {
    if (word2.empty()) {
      return static_cast<int>(word1.size());
    }
    if (word1.empty()) {
      return static_cast<int>(word2.size());
    }
    vector<vector<int>> cache(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (size_t i = 0; i <= word1.size(); ++i) {
      cache[i][0] = static_cast<int>(i);
    }
    for (size_t i = 0; i <= word2.size(); ++i) {
      cache[0][i] = static_cast<int>(i);
    }
    for (size_t i = 1; i <= word1.size(); ++i) {
      for (size_t j = 1; j <= word2.size(); ++j) {
        if (word1.at(i - 1) == word2.at(j - 1)) {
          cache[i][j] = cache[i - 1][j - 1];
        } else {
          cache[i][j] = min(min(cache[i - 1][j], cache[i][j - 1]), cache[i - 1][j - 1]) + 1;
        }
      }
    }
    return cache[word1.size()][word2.size()];
  }
};

TEST_CASE("Test the solution for problem 'Edit Distance'") {
  Solution sln_instance;
  CHECK(sln_instance.minDistance("horse", "ros") == 3);
  CHECK(sln_instance.minDistance("intention", "execution") == 5);
}
