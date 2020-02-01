#include "catch.hpp"
#include <string>

using std::string;

class Solution {
public:
  int longestValidParentheses(string s) {
    return 0;
  }
};

TEST_CASE("Test the solution for problem \"Longest Valid Parentheses\"") {
  Solution sln_instance;
  CHECK(sln_instance.longestValidParentheses("(()") == 2);
  CHECK(sln_instance.longestValidParentheses(")()())") == 4);
  CHECK(sln_instance.longestValidParentheses("(()())") == 4);
}
