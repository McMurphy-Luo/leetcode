#include "catch.hpp"
#include <string>
#include <deque>
#include <vector>

using std::string;
using std::deque;
using std::max;
using std::vector;

struct Parenthesis {
  int position;
  int peer_position;
};

class Solution {
public:
  vector<Parenthesis> Analyze(const string& source) {
    deque<Parenthesis> stack_for_parenthese_validation;
    vector<Parenthesis> result;
    result.reserve(source.size());
    for (int index = 0; index < source.size(); ++index) {
      Parenthesis item;
      assert(source.at(index) == '(' || source.at(index) == ')');
      item.position = index;
      item.peer_position = -1;
      if (source.at(index) == '(') {
        stack_for_parenthese_validation.push_back(item);
      } else if (stack_for_parenthese_validation.empty()) {
        
      } else {
        Parenthesis peer = stack_for_parenthese_validation.back();
        stack_for_parenthese_validation.pop_back();
        item.peer_position = peer.position;
        result[item.peer_position].peer_position = item.position;
      }
      result.push_back(item);
    }
    return result;
  }

public:
  int longestValidParentheses(string s) {
    vector<Parenthesis> analyze_result = Analyze(s);
    int begin = -1;
    int end = -1;
    int longest = 0;
    for (int index = 0; index < analyze_result.size(); ++index) {
      Parenthesis current = analyze_result.at(index);
      if (current.peer_position == -1) {
        begin = -1;
        end = -1;
      }
      else {
        if (begin == -1) {
          begin = current.position;
        }
        end = current.position;
        longest = max(longest, end - begin + 1);
      }
    }
    return longest;
  }
};

TEST_CASE("Test the solution for problem \"Longest Valid Parentheses\"") {
  Solution sln_instance;
  CHECK(sln_instance.longestValidParentheses("(()") == 2);
  CHECK(sln_instance.longestValidParentheses(")()())") == 4);
  CHECK(sln_instance.longestValidParentheses("(()())") == 6);
  CHECK(sln_instance.longestValidParentheses("()()))") == 4);
  CHECK(sln_instance.longestValidParentheses("()(()") == 2);
}
