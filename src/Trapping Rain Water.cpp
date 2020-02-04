#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int trap(vector<int>& height) {
    return 0;
  }
};

TEST_CASE("Test the solution for problem \"Trapping Rain Water\"") {
  Solution sln_instance;
  vector<int> input{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
  CHECK(sln_instance.trap(input) == 6);
}