#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>

using std::vector;


/**
 * This solution does not use the best algorithm.
 * This solution is a brute force solution to this problem
 * Although after read the answer at the solution page at leetcode, I already know the best solution
 * I decide to keep this brute force solution.
 */
class Solution {
public:
  int maxArea(vector<int>& height) {
    for (vector<int>::const_iterator it = height.cbegin(); it != height.cend(); ++it) {
      
    }
  }
};

TEST_CASE("Test case for the problem 'Container With Most Water'") {
  Solution solution_instance;
  vector<int> input_1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  CHECK(solution_instance.maxArea(input_1) == 49);
}