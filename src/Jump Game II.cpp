#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int jump(vector<int>& nums) {
    int jumped = 0;
    int next_jump = 0;
    if (nums.size() == 1) {
      return 0;
    }
    nums.at(nums.size() - 1) = std::numeric_limits<int>::max();
    do {
      next_jump = NextJump(next_jump, nums);
      ++jumped;
    } while (next_jump != (nums.size() - 1));
    return jumped;
  }

  int NextJump(int from, vector<int>& nums) {
    int can_jump = nums.at(from);
    if ((from + can_jump) >= (nums.size() - 1)) {
      return static_cast<int>(nums.size()) - 1;
    }
    int next_jump_maximum = 0;
    int next_jump = 0;
    for (int i = 1; i <= can_jump; ++i) {
      if (nums.at(from + i) + i - 1 > next_jump_maximum) {
        next_jump_maximum = nums.at(from + i) + i - 1;
        next_jump = from + i;
      }
    }
    return next_jump;
  }
};

TEST_CASE("Test the solution for problem 'Jump Game II'") {
  vector<int> input = { 2, 3, 1, 1, 4 };
  Solution sln_instance;
  CHECK(sln_instance.jump(input) == 2);
  input = { 2, 3, 0, 1, 4 };
  CHECK(sln_instance.jump(input) == 2);
}
