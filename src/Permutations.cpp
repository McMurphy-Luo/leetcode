#include "catch.hpp"
#include <vector>

using std::vector;
using std::find;
using std::find_if;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 0) {
      return { };
    }
    return RecursivePermute(nums, static_cast<int>(nums.size()) - 1);
  }

  vector<vector<int>> RecursivePermute(const vector<int>& nums, int end) {
    if (end == 0) {
      return { { nums.at(0)} };
    }
    vector<vector<int>> result_of_next_permutation = RecursivePermute(nums, end - 1);
    vector<vector<int>> result;
    int current_number = nums.at(end);
    for (
      vector<vector<int>>::iterator it = result_of_next_permutation.begin();
      it != result_of_next_permutation.cend();
      ++it
    ) {
      for (int index = 0; index <= it->size(); ++index) {
        vector<int> permutation = *it;
        permutation.insert(permutation.begin() + index, current_number);
        result.push_back(permutation);
      }
    }
    return result;
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