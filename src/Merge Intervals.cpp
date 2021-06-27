#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return intervals;
    }
    vector<vector<int>> result;
    std::sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) {
      return lhs[0] < rhs[0];
    });
    result.push_back(intervals[0]);
    vector<vector<int>>::iterator it = intervals.begin() + 1;
    while (it != intervals.end()) {
      if (Overlapping(result.back(), *it)) {
        Merge(result.back(), *it);
        ++it;
      } else {
        result.push_back(*it);
        ++it;
      }
    }
    return result;
  }

  bool Overlapping(const vector<int>& lhs, const vector<int>& rhs) {
    return !((lhs[1] < rhs[0]) || (lhs[0] > rhs[1]));
  }

  void Merge(vector<int>& lhs, const vector<int>& rhs) {
    lhs[0] = std::min(lhs[0], rhs[0]);
    lhs[1] = std::max(lhs[1], rhs[1]);
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
