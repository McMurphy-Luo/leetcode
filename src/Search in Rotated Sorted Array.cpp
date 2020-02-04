#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    return RecursiveSearch(nums, 0, static_cast<int>(nums.size()) - 1, target);
  }


  int RecursiveSearch(const vector<int>& nums, int begin, int end, int target) {
    int middle = (begin + end) / 2;
    assert(middle >= begin);
    int greater_or_less = 0;
    if (target > nums.at(middle)) {
      greater_or_less = 1;
    }
    else if (target < nums.at(middle)) {
      greater_or_less = -1;
    }
    if (greater_or_less == 0) {
      return middle;
    }
    int left_find_result = -1;
    do {
      if (middle == begin) {
        break;
      }
      assert(middle > begin);
      if (
        greater_or_less < 0
        &&
        nums.at(begin) < nums.at(middle)
        &&
        nums.at(begin) > target
      ) {
        break;
      }
      if (
        greater_or_less > 0
        &&
        nums.at(begin) < nums.at(middle)
      ) {
        break;
      }
      left_find_result = RecursiveSearch(nums, begin, middle - 1, target);
    } while (false);
    if (left_find_result != -1) {
      return left_find_result;
    }
    int right_find_result = -1;
    do {
      if (middle == end) {
        break;
      }
      assert(middle < end);
      if (
        greater_or_less < 0
        &&
        nums.at(middle) < nums.at(end)
      ) {
        break;
      }
      if (
        greater_or_less > 0
        &&
        nums.at(middle) < nums.at(end)
        &&
        nums.at(end) < target
        ) {
        break;
      }
      right_find_result = RecursiveSearch(nums, middle + 1, end, target);
    } while (false);
    if (right_find_result != -1) {
      return right_find_result;
    }
    return -1;
  }
};

TEST_CASE("Test the solution for problem \"Search in Rotated Sorted Array\"") {
  Solution sln_instance;
  vector<int> input_array { 4,5,6,7,0,1,2 };
  CHECK(sln_instance.search(input_array, 0) == 4);
  CHECK(sln_instance.search(input_array, 3) == -1);
  input_array = { 3,4,5,6,1,2 };
  CHECK(sln_instance.search(input_array, 2) == 5);
}