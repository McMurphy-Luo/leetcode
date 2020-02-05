#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    if (candidates.empty()) {
      return {};
    }
    int current_run_value = candidates.back();
    int count = 0;
    vector<vector<int>> result;
    vector<int> candidates_next = candidates;
    candidates_next.pop_back();
    while (count * current_run_value <= target) {
      if (target - count * current_run_value == 0) {
        result.push_back(vector<int>(count, current_run_value));
        break;
      }
      vector<vector<int>> combination_of_subrouting = combinationSum(candidates_next, target - count * current_run_value);
      for (
        vector<vector<int>>::iterator it = combination_of_subrouting.begin();
        it != combination_of_subrouting.end();
        ++it
      ) {
        it->insert(it->end(), count, current_run_value);
      }
      result.insert(result.end(), combination_of_subrouting.cbegin(), combination_of_subrouting.cend());
      ++count;
    }
    return result;
  }
};

namespace
{
  bool ArraySame(const vector<int>& lhs, const vector<int>& rhs) {
    if (rhs.size() != lhs.size()) {
      return false;
    }
    for (vector<int>::const_iterator it = lhs.begin(); it != lhs.end(); ++it) {
      if (find(rhs.begin(), rhs.end(), *it) == rhs.end()) {
        return false;
      }
    }
    return true;
  }

  bool Contains(const vector<vector<int>>& array_of_array, const vector<int>& target) {
    for (
      vector<vector<int>>::const_iterator it = array_of_array.cbegin();
      it != array_of_array.cend();
      ++it
      ) {
      if (ArraySame(*it, target)) {
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
}

TEST_CASE("Test the solution for problem \"Combination Sum\"") {
  Solution sln_instance;
  vector<int> input{ 2,3,6,7 };
  vector<vector<int>> expected_output{ {7}, {2, 2, 3} };
  vector<vector<int>> output = sln_instance.combinationSum(input, 7);
  CHECK(ArrayOfArraySame(expected_output, output));
  input = { 2,3,5 };
  expected_output = {
    {2, 2, 2, 2},
    {2, 3, 3},
    {3, 5}
  };
  output = sln_instance.combinationSum(input, 8);
  CHECK(ArrayOfArraySame(expected_output, output));
}
