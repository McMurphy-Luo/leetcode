#include "catch.hpp"
#include <vector>
#include "Sort.h"

using std::vector;
using std::ceil;

struct BinarySearchResult {
  int index_of_target;
  int upper_bound;
  int lower_bound;
};

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return { -1, -1 };
    }
    return { FindLowerBound(nums, target), FindUpperBound(nums, target) };
  }

  int FindUpperBound(const vector<int>& nums, int target) {
    int end = nums.size() - 1;
    int begin = 0;
    if (nums.at(end) < target) {
      return -1;
    }
    while (end > begin) {
      int middle = (end + begin) / 2 + (end + begin) % 2;
      if (nums.at(middle) > target) {
        end = middle - 1;
      }
      else {
        begin = middle;
      }
    }
    assert(end == begin);
    if (nums.at(end) == target) {
      return end;
    }
    else {
      return -1;
    }
    return end;
  }

  int FindLowerBound(const vector<int>& nums, int target) {
    int end = nums.size() - 1;
    int begin = 0;
    if (nums.at(begin) > target) {
      return -1;
    }
    while (end > begin) {
      int middle = (begin + end) / 2;
      if (nums.at(middle) < target) {
        begin = middle + 1;
      }
      else {
        end = middle;
      }
    }
    assert(end == begin);
    if (nums.at(begin) == target) {
      return begin;
    }
    else {
      return -1;
    }
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
