#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    return 0;
  }
};

TEST_CASE("Test the solution for problem 'Minimum Path Sum'") {
  Solution sln_instance;
  vector<vector<int>> input = { {1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
  CHECK(sln_instance.minPathSum(input) == 7);
  input = { {1, 2, 3 }, { 4, 5, 6 }};
  CHECK(sln_instance.minPathSum(input) == 12);
}
