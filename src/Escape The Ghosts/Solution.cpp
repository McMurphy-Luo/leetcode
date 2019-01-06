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

      if (ghost_target_distance >= me_target_distance) {
        return false;
      }
    }

    return true;


  }
};