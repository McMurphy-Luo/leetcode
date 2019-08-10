#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using std::sort;
using std::mismatch;
using std::map;
using std::pair;

namespace
{
  bool UnorderedArrayEqual(const vector<int>& input_1, const vector<int>& input_2) {
    if (input_1.size() != input_2.size()) {
      return false;
    }
    vector<int> input_1_copy = input_1;
    vector<int> input_2_copy = input_2;
    sort(input_1_copy.begin(), input_1_copy.end());
    sort(input_2_copy.begin(), input_2_copy.end());
    return mismatch(input_1_copy.begin(), input_1_copy.end(), input_2_copy.begin()).first == input_1_copy.end();
  }

  bool VectorInVector(const vector<int>& input, const vector<vector<int>>& container) {
    for (vector<vector<int>>::const_iterator it = container.cbegin(); it != container.cend(); ++it) {
      if (UnorderedArrayEqual(input, *it)) {
        return true;
      }
    }
    return false;
  }
}

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    
  }

  vector<vector<int>> NSum(const vector<int>& nums) {

  }

  pair<bool, vector<int>> NSum(const map<int, size_t>& numbers, int target_number, size_t number_count_need_to_retrieve) {
    if (number_count_need_to_retrieve == 1) {
      if (numbers.find(target_number) == numbers.end()) {
        return { false, {} };
      }
      return { false, {} };
    }
  }
};

TEST_CASE("Test the solution for problem '3Sum'") {
  Solution sln_instance;
  vector<int> input {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> result = sln_instance.threeSum(input);
  REQUIRE(VectorInVector(vector<int>{-1, 0, 1}, result));
  REQUIRE(VectorInVector(vector<int>{-1, -1, 2}, result));
}