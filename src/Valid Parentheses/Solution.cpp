/**
 * @author McMurphy.Luo@gmail.com
 * @date Feb/11/2018
 * @brief solution to problem https://leetcode.com/problems/valid-parentheses/
 */

#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include <string>
#include <stack>
#include <iostream>
#include <cassert>

using std::string;
using std::stack;
using std::cin;

class Solution {
public:
  bool isValid(string s) {
    stack<char> parentheses_stack;
    for (string::const_iterator it = s.cbegin(); it != s.cend(); ++it) {
      char current_char = *it;
      if (
        current_char == '{'
        ||
        current_char == '('
        ||
        current_char == '['
        )
      {
        parentheses_stack.push(current_char);
      }
      else if (
        current_char == ')'
        ||
        current_char == '}'
        ||
        current_char == ']'
        )
      {
        char char_matched = 0;
        switch (current_char) {
        case ')':
          char_matched = '(';
          break;
        case '}':
          char_matched = '{';
          break;
        case ']':
          char_matched = '[';
          break;
        }

        if (parentheses_stack.empty()) {
          return false;
        }

        if (parentheses_stack.top() == char_matched) {
          parentheses_stack.pop();
        }
        else {
          return false;
        }
      }
      else {
        assert(false);
      }
    }
    
    if (!parentheses_stack.empty()) {
      return false;
    }
    return true;
  }
};

TEST_CASE("Test the solution of for problem 'Valid Parentheses'.") {
  Solution solution;
  REQUIRE(solution.isValid("()"));
  REQUIRE(solution.isValid("()[]{}"));
  REQUIRE(!solution.isValid("(]"));
  REQUIRE(!solution.isValid("([)]"));
  REQUIRE(solution.isValid("{[]}"));
}

int main(int argc, char* argv[]) {
  int result = Catch::Session().run(argc, argv);
  cin.get();
  return result;
}