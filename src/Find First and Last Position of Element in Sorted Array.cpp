#include "catch.hpp"
#include <vector>
#include "Sort.h"

using std::vector;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    return {};
  }
};

int IntComparator(const int& lhs, const int& rhs) {
  if (lhs < rhs) {
    return -1;
  }
  else if (lhs > rhs) {
    return 1;
  }
  return 0;
}

TEST_CASE("Test the solution for problem \"Find First and Last Position of Element in Sorted Array\"") {
  Solution sln_instance;
  vector<int> input{ 5, 7, 7, 8, 8, 10 };
  vector<int> output = sln_instance.searchRange(input, 8);
  vector<int> output_expected{ 3,4 };
  CHECK(ArrayEquals<vector<int>::const_iterator, int>(output.begin(), output.end(), output_expected.begin(), output_expected.end(), IntComparator));
  input = { 5, 7, 7, 8, 8, 10 };
  output = sln_instance.searchRange(input, 6);
  output_expected = { -1, -1 };
  CHECK(ArrayEquals<vector<int>::const_iterator, int>(output.begin(), output.end(), output_expected.begin(), output_expected.end(), IntComparator));
}
