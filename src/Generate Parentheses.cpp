#include "catch.hpp"
#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
using std::sort;
using std::unique;

namespace
{
  bool UnorderedArrayEqual(const vector<string>& lhs, const vector<string>& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    vector<string> lhs_copy = lhs;
    vector<string> rhs_copy = rhs;
    sort(lhs_copy.begin(), lhs_copy.end());
    sort(rhs_copy.begin(), rhs_copy.end());
    for (size_t index = 0; index < rhs_copy.size(); ++index) {
      if (rhs_copy.at(index) != rhs_copy.at(index)) {
        return false;
      }
    }
    return true;
  }
}

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 1) {
      return { "()" };
    }
    vector<string> result_of_subroutine = generateParenthesis(n - 1);
    vector<string> result;
    for (const string& item : result_of_subroutine) {
      result.push_back("(" + item + ")");
      result.push_back("()" + item);
      result.push_back(item + "()");
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
  }
};

TEST_CASE("Test the solution for problem 'Generate Parentheses'") {
  Solution sln_instance;
  CHECK(UnorderedArrayEqual(sln_instance.generateParenthesis(3), { "((()))", "(()())", "(())()", "()(())", "()()()" }));
  CHECK(
    UnorderedArrayEqual(
      sln_instance.generateParenthesis(4),
      { "(((())))", "((()()))", "((())())", "((()))()", "(()(()))",
      "(()()())", "(()())()", "(())(())", "(())()()", "()((()))",
      "()(()())", "()(())()", "()()(())", "()()()()"}
    )
  );
}