#include "catch.hpp"
#include <vector>
#include "Sort.h"

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    return {};
  }
};

bool Contains(const vector<vector<int>>& array_of_array, const vector<int>& target) {
  for (
    vector<vector<int>>::const_iterator it = array_of_array.cbegin();
    it != array_of_array.cend();
    ++it
    ) {
    if (ArrayEquals<vector<int>::const_iterator, int>(it->cbegin(), it->cend(), target.cbegin(), target.cend(), IntComparator)) {
      return true;
    }
  }
  return false;
}

bool ArrayOfArraySame(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  for (
    vector<vector<int>>::const_iterator it = lhs.begin();
    it != lhs.end();
    ++it
  ) {
    if (!Contains(rhs, *it)) {
      return false;
    }
  }
  return true;
}

TEST_CASE("Test the solution for problem \"Combination Sum\"") {
  Solution sln_instance;
  vector<int> input{ 2,3,6,7 };
  vector<vector<int>> output{ {7}, {2, 2, 3} };
  CHECK(ArrayOfArraySame(sln_instance.combinationSum(input, 7), output));
  input = { 2,3,5 };
  output = {
    {2, 2, 2, 2},
    {2, 3, 3},
    {3, 5}
  };
  CHECK(ArrayOfArraySame(sln_instance.combinationSum(input, 8), output));
}
