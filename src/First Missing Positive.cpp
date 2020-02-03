#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    return 0;
  }
};

TEST_CASE("Test the solution for problem \"First Missing Positive\"") {
  Solution sln_instance;
  vector<int> input { 1,2,0 };
  CHECK(3 == sln_instance.firstMissingPositive(input));
  input = { 3, 4, -1, 1 };
  CHECK(2 == sln_instance.firstMissingPositive(input));
  input = { 7, 8, 9, 11, 12 };
  CHECK(1 == sln_instance.firstMissingPositive(input));
}
