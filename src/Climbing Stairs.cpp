#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    vector<int> steps;
    steps.resize(n);
    steps[0] = 1;
    steps[1] = 2;
    for (size_t i = 2; i < n; ++i) {
      steps[i] = (steps[i - 1] + steps[i - 2]);
    }
    return steps[n - 1];
  }
};

TEST_CASE("Test the solution for problem 'Climbing Stairs'") {
  Solution sln_instance;
  CHECK(sln_instance.climbStairs(2) == 2);
  CHECK(sln_instance.climbStairs(3) == 3);
}
