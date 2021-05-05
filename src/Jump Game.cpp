#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    if (nums.size() == 0) {
      return false;
    }
    if (nums.size() == 1 || nums.at(0) >= (nums.size() - 1)) {
      return true;
    }
    int next_jump = 0;
    int i = 1;
    while (i <= nums.at(next_jump)) {
      if (nums.at(i + next_jump) + next_jump + i > nums.at(next_jump) + next_jump) {
        next_jump = next_jump + i;
        i = 1;
        if (nums.at(next_jump) + next_jump >= nums.size() - 1) {
          return true;
        }
      } else {
        ++i;
      }
    }
    return false;
  }
};

TEST_CASE("Test the solution for problem 'Jump Game'") {
  vector<int> input{ 2,3,1,1,4 };
  Solution sln_instance;
  CHECK(sln_instance.canJump(input));
  input = { 3,2,1,0,4 };
  CHECK(!sln_instance.canJump(input));
  input = { 2, 0 };
  CHECK(sln_instance.canJump(input));
  input = { 2,0,0 };
  CHECK(sln_instance.canJump(input));
}
