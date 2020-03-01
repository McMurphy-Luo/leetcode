#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    return 0;
  }
};

TEST_CASE("Test the solution for problem \"Maximum Subarray\"") {
  vector<int> input{ -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  Solution sln_instance;
  CHECK(sln_instance.maxSubArray(input) == 6);
}