#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>
#include <cstdlib>
#include <cassert>

using std::vector;
using std::size_t;
using std::abs;

class Solution {
public:
  size_t PointDistance(int x1, int y1, int x2, int y2) {
    return static_cast<size_t>(abs(x2 - x1)) + static_cast<size_t>(abs(y2 - y1));
  }

  bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    assert(target.size() == 2);
    size_t me_target_distance = PointDistance(0, 0, target[0], target[1]);
    for (const vector<int>& item : ghosts) {
      assert(item.size() == 2);
      size_t ghost_target_distance = PointDistance(target[0], target[1], item[0], item[1]);
      if (ghost_target_distance <= me_target_distance) {
        return false;
      }
    }
    return true;
  }
};

TEST_CASE("Test for solution of problem \"\"") {
  Solution solution_instance;
  vector<vector<int>> ghosts_1;
  vector<int> ghost;
  ghost.push_back(1);
  ghost.push_back(0);
  ghosts_1.push_back(ghost);
  ghost.clear();
  ghost.push_back(0);
  ghost.push_back(3);
  ghosts_1.push_back(ghost);
  ghost.clear();
  vector<int> target_1;
  target_1.push_back(0);
  target_1.push_back(1);
  REQUIRE(solution_instance.escapeGhosts(ghosts_1, target_1));

  vector<vector<int>> ghosts_2;
  ghost.clear();
  ghost.push_back(1);
  ghost.push_back(0);
  ghosts_2.push_back(ghost);
  vector<int> target_2;
  target_2.push_back(1);
  target_2.push_back(0);
  REQUIRE_FALSE(solution_instance.escapeGhosts(ghosts_2, target_2));

  vector<vector<int>> ghosts_3;
  ghost.clear();
  ghost.push_back(2);
  ghost.push_back(0);
  ghosts_3.push_back(ghost);
  vector<int> target_3;
  target_3.push_back(1);
  target_3.push_back(0);

  REQUIRE_FALSE(solution_instance.escapeGhosts(ghosts_3, target_3));
}