#include "catch.hpp"
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::sort;

namespace
{
  bool UnorderedArrayEqual(const vector<string>& lhs, const vector<string>& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    sort(lhs.begin(), lhs.end());
    sort(rhs.begin(), rhs.end());
    for (size_t index = 0; index < lhs.size(); ++index) {
      if (lhs.at(index) != rhs.at(index)) {
        return false;
      }
    }
    return true;
  }
}

class Solution {
public:
  vector<string> generateParenthesis(int n) {

  }
};

TEST_CASE("Test the solution for problem 'Generate Parentheses'") {
  Solution sln_instance;
  CHECK(UnorderedArrayEqual(sln_instance.generateParenthesis(3), { "((()))", "(()())", "(())()", "()(())", "()()()" }));
}