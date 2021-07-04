#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    int columns = static_cast<int>(grid.front().size());
    int rows = static_cast<int>(grid.size());
    vector<vector<int>> min_path(rows, vector<int>(columns, -1));
    
    for (int i = rows - 1; i >= 0; --i) {
      for (int j = columns - 1; j >= 0; --j) {
        if (i == rows - 1 && j == columns - 1) {
          min_path[i][j] = grid[i][j];
          continue;
        }
        int min = std::numeric_limits<int>::max();
        if (j < columns - 1) {
          min = std::min(min, min_path[i][j + 1]);
        }
        if (i < rows - 1) {
          min = std::min(min, min_path[i + 1][j]);
        }
        min_path[i][j] = min + grid[i][j];
      }
    }
    return min_path[0][0];
  }
};

TEST_CASE("Test the solution for problem 'Minimum Path Sum'") {
  Solution sln_instance;
  vector<vector<int>> input = { {1, 3, 1 }, { 1, 5, 1 }, { 4, 2, 1 } };
  CHECK(sln_instance.minPathSum(input) == 7);
  input = { {1, 2, 3 }, { 4, 5, 6 }};
  CHECK(sln_instance.minPathSum(input) == 12);
}
