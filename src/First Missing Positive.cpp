/**
 * @author McMurphy.Luo
 * @Note: This algorithm is not found by me
 * I refered the idea at this web page https://leetcode.wang/leetCode-41-First-Missing-Positive.html
 * Thanks to @windliang (https://github.com/windliang)
 */

#include "catch.hpp"
#include <vector>

using std::vector;
using std::swap;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    for (int index = 0; index < nums.size(); ++index) {
      do {
        if (nums.at(index) <= 0) {
          break;
        }
        if (nums.at(index) == index + 1) {
          break;
        }
        if (nums.at(index) > nums.size() || nums.at(index) <= 0) {
          break;
        }
        if (nums.at(index) == nums[static_cast<size_t>(nums[index]) - 1]) {
          break;
        }
        swap(nums[index], nums[static_cast<size_t>(nums[index]) - 1]);
      } while (true);
    }
    int index = 0;
    for (; index < nums.size(); ++index) {
      if (nums.at(index) != index + 1) {
        return index + 1;
      }
    }
    return index + 1;
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
