#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>
#include <algorithm>

using std::vector;
using std::min;
using std::max;

class Solution {
public:
  int maxArea(vector<int>& height) {
    assert(height.size() >= 2);
    int max_area = 0;
    size_t i = 0;
    size_t j = height.size() - 1;
    int begin = 0;
    int end = 0;
    while (i < j) {
      bool new_area_shall_be_calculated = false;
      if (height.at(i) > begin) {
        new_area_shall_be_calculated = true;
        begin = height.at(i);
      }
      if (height.at(j) > end) {
        new_area_shall_be_calculated = true;
        end = height.at(j);
      }
      if (new_area_shall_be_calculated) {
        max_area = max(max_area, static_cast<int>(min(end, begin) * (j - i)));
      }
      if (end < begin) {
        --j;
      }
      else {
        ++i;
      }
    }
    return max_area;
  }
};

TEST_CASE("Test case for the problem 'Container With Most Water'") {
  Solution solution_instance;
  vector<int> input_1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  CHECK(solution_instance.maxArea(input_1) == 49);
}