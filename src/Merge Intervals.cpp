#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    return {};
  }
};

bool ArrayEquals(const vector<int>& lhs, const vector<int>& rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  for (size_t i = 0; i < lhs.size(); ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

bool ArrayEquals(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  for (size_t i = 0; i < lhs.size(); ++i) {
    if (!ArrayEquals(lhs[i], rhs[i])) {
      return false;
    }
  }
  return true;
}

TEST_CASE("Test the solution for problem 'Merge Intervals'") {
  Solution sln_instance;
  vector<vector<int>> input = {
    {1, 3},{2, 6},{8, 10},{15, 18}
  };
  vector<vector<int>> output = sln_instance.merge(input);
  CHECK(ArrayEquals(output, { {1,6 }, { 8,10 }, { 15,18 }}));
  input = { {1,4 }, { 4,5 } };
  output = sln_instance.merge(input);
  CHECK(ArrayEquals(output, { {1,5} }));
}
