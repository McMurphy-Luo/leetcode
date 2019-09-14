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
      if (lhs_copy.at(index) != rhs_copy.at(index)) {
        return false;
      }
    }
    return true;
  }
}

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> generation_result_stored;
    GenerateParenthesisDP(n, generation_result_stored);
    return generation_result_stored.at(n - 1);
  }

  void GenerateParenthesisDP(int n, vector<vector<string>>& result_stored) {
    if (n == 1) {
      assert(result_stored.size() == 0);
      result_stored.push_back({ "()" });
      return;
    }
    if (n == 2) {
      GenerateParenthesisDP(1, result_stored);
      assert(result_stored.size() == 1);
      result_stored.push_back({ "()()", "(())" });
      return;
    }
    GenerateParenthesisDP(n - 1, result_stored);
    assert(result_stored.size() == n - 1);
    vector<string> result;
    string result_instance;
    for (size_t i = 0; static_cast<int>(i) < n; ++i) {
      if (i == 0) {
        for (size_t j = 0; j < result_stored.at(static_cast<size_t>(n - 2)).size(); ++j) {
          result_instance = "()" + result_stored.at(static_cast<size_t>(n - 2)).at(j);
          result.push_back(result_instance);
        }
        continue;
      }
      if (i == (n - 1)) {
        for (size_t j = 0; j < result_stored.at(static_cast<size_t>(n - 2)).size(); ++j) {
          result_instance = "(" + result_stored.at(static_cast<size_t>(n - 2)).at(j) + ")";
          result.push_back(result_instance);
        }
        continue;
      }
      for (size_t j = 0; j < result_stored.at(i - 1).size(); ++j) {
        for (size_t m = 0; m < result_stored.at(n - i - 2).size(); ++m) {
          result.push_back("(" + result_stored.at(i - 1).at(j) + ")" + result_stored.at(n - i - 2).at(m));
        }
      }
    }
    result_stored.push_back(result);
  }
};

TEST_CASE("Test the solution for problem 'Generate Parentheses'") {
  Solution sln_instance;
  CHECK(UnorderedArrayEqual(sln_instance.generateParenthesis(3), { "((()))", "(()())", "(())()", "()(())", "()()()" }));
  CHECK(
    UnorderedArrayEqual(
      sln_instance.generateParenthesis(4),
      { "(((())))", "((()()))", "((())())", "((()))()", "(()(()))", "(()()())", "(()())()", "(())(())", "(())()()", "()((()))", "()(()())", "()(())()", "()()(())", "()()()()" }
    )
  );
}