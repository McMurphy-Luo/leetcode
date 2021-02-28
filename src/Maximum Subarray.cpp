#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    vector<int> sums;
    sums.reserve(nums.size());
    for (size_t i = 0; i < nums.size(); ++i) {
      if (i > 0) {
        sums.push_back(sums[i - 1] + nums[i]);
      } else {
        sums.push_back(nums[0]);
      }
    }
    int max_sub_array = std::numeric_limits<int>::min();
    for (size_t i = 0; i < sums.size(); ++i) {
      max_sub_array = std::max(max_sub_array, sums[i]);
      for (size_t j = i + 1; j < sums.size(); ++j) {
        max_sub_array = std::max(max_sub_array, sums[j] - sums[i]);
      }
    }
    return max_sub_array;
  }
};

TEST_CASE("Test the solution for problem \"Maximum Subarray\"") {
  vector<int> input { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
  Solution sln_instance;
  CHECK(sln_instance.maxSubArray(input) == 6);
  input = { 1 };
  CHECK(sln_instance.maxSubArray(input) == 1);
  input = { 0 };
  CHECK(sln_instance.maxSubArray(input) == 0);
  input = { -1 };
  CHECK(sln_instance.maxSubArray(input) == -1);
  input = { -100000 };
  CHECK(sln_instance.maxSubArray(input) == -100000);
}
