#include "catch.hpp"
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
using std::endl;
using std::advance;
using std::binary_search;

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
    sort(nums.begin(), nums.end());
    int number_1 = 0;
    int number_2 = 0;
    int number_3 = 0;
    vector<vector<int>> result;
    for (
      size_t index_outer = 0;
      index_outer < nums.size();
      ++index_outer
      ) {
      if (index_outer >= 1 && nums.at(index_outer) == nums.at(index_outer - 1)) {
        continue;
      }
      number_1 = nums.at(index_outer);
      for (
        size_t index_inner = index_outer + 1;
        index_inner < nums.size();
        ++index_inner
        ) {
        if (index_inner >= index_outer + 2 && nums.at(index_inner - 1) == nums.at(index_inner)) {
          continue;
        }
        number_2 = nums.at(index_inner);
        vector<int>::iterator iter_for_number_three = nums.begin();
        advance(iter_for_number_three, index_inner + 1);
        bool b_found = binary_search(iter_for_number_three, nums.end(), 0 - number_1 - number_2);
        if (b_found) {
          result.push_back({ number_1, number_2, 0 - number_1 - number_2 });
        }
      }
    }
    return result;
  }
};

TEST_CASE("Test the solution for problem '3Sum'") {
  Solution sln_instance;
  vector<int> input{ -1, 0, 1, 2, -1, -4 };
  vector<vector<int>> result = sln_instance.threeSum(input);
  CHECK(result.size() == 2);
  CHECK(VectorInVector(vector<int>{-1, 0, 1}, result));
  CHECK(VectorInVector(vector<int>{-1, -1, 2}, result));
  vector<int> input_2{ 0, 0, 0, 0 };
  result = sln_instance.threeSum(input_2);
  CHECK(result.size() == 1);
  CHECK(VectorInVector(vector<int>{0, 0, 0}, result));
}