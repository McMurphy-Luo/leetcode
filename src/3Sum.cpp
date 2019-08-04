#include "catch.hpp"
#include <vector>
#include <algorithm>

using std::vector;

namespace
{
  bool UnorderedArrayEqual(const vector<int>& input_1, const vector<int>& input_2) {
    return false;
  }

  bool VectorInVector(const vector<int>& input, const vector<vector<int>>& container) {
    for (vector<vector<int>>::const_iterator it = container.cbegin(); it != container.cend(); ++it) {

    }
    return false;
  }
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    return {};
  }
};

TEST_CASE("Test the solution for problem '3Sum'") {

}