#include "catch.hpp"
#include <vector>

using std::vector;
using std::find;
using std::find_if;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    return {};
  }
};

namespace
{
  bool ArrayEquals(const vector<int>& lhs, const vector<int>& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (size_t index = 0; index < lhs.size(); ++index) {
      if (rhs.at(index) != lhs.at(index)) {
        return false;
      }
    }
    return true;
  }

  bool ArrayOfArraySame(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (
      vector<vector<int>>::const_iterator it = lhs.cbegin();
      it != lhs.cend();
      ++it
      ) {
      const vector<int>& current = *it;
      if (find_if(rhs.cbegin(), rhs.cend(), [&current](const vector<int>& item) -> bool {
        return ArrayEquals(item, current);
        }) == rhs.end()) {
        return false;
      }
    }
    return true;
  }
}

TEST_CASE("Test the solution for problem \"Permutations\"") {
  Solution sln_instance;
  vector<int> input{ 1,2,3 };
  vector<vector<int>> output = sln_instance.permute(input);
  vector<vector<int>> expected_output{
    { 1, 2, 3 },
    { 1, 3, 2 },
    { 2, 1, 3 },
    { 2, 3, 1 },
    { 3, 1, 2 },
    { 3, 2, 1 }
  };
  CHECK(ArrayOfArraySame(output, expected_output));
}