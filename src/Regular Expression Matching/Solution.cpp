/**
 * @author McMurphy.Luo
 * @date June/30/2019
 * @brief The solution for problem https://leetcode.com/problems/regular-expression-matching/
 */

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>

using std::string;

class State {
public:
  State(char state_char, bool is_any, bool is_repeat)
    : state_char_(state_char)
    , is_any_(is_any)
    , is_repeat_(is_repeat)
    , next_(nullptr) {

  }

  void SetValue(char value) {
    state_char_ = value;
  }

  char Value() const {
    return state_char_;
  }

  void SetAny(bool is_any) {
    is_any_ = is_any;
  }

  bool Any() const {
    return is_any_;
  }

  void SetRepeat(bool is_repeat) {
    is_repeat_ = is_repeat;
  }

  bool Repeat() const {
    return is_repeat_;
  }

  void SetNext(State* next) {
    next_ = next;
  }

  State* Next() const {
    return next_;
  }

private:
  char state_char_;
  bool is_any_;
  bool is_repeat_;
  State* next_;
};

State* ParsePattern(const string& pattern) {
  size_t index = 0;
  if (pattern.size() == 0) {
    return nullptr;
  }
  char current_char = pattern.at(index);
  bool is_any = current_char == '.';  
  bool is_repeat = false;
  if (index + 1 < pattern.size()) {
    char next_char = pattern.at(index + 1);
    is_repeat = next_char == '*';
  }
  State* current_state = new State(current_char, is_any, is_repeat);
  current_state->SetNext(ParsePattern(pattern.substr(is_repeat ? 2 : 1)));
  return current_state;
}

bool RunPattern(State* pattern, const string& string_to_match) {
  size_t index = 0;
  State* current_pattern = pattern;
  while (index < string_to_match.size() && current_pattern) {
    char current = string_to_match.at(index);
  }
  return index == string_to_match.size() && nullptr == current_pattern->Next();
}

void DeletePattern(State* pattern) {
  if (pattern) {
    State* next = pattern->Next();
    delete pattern;
    DeletePattern(next);
  }
}

class Solution {
public:
  bool isMatch(string s, string p) {
    State* pattern = ParsePattern(p);
    bool result = RunPattern(pattern, s);
    DeletePattern(pattern);
    return result;
  }
};

TEST_CASE("Test the solution for prblem 'Regular Expression Matching'") {
  Solution sln_instance;
  CHECK_FALSE(sln_instance.isMatch("aa", "a"));
  CHECK(sln_instance.isMatch("aa", "a*"));
  CHECK(sln_instance.isMatch("ab", ".*"));
  CHECK(sln_instance.isMatch("aab", "c*a*b"));
  CHECK_FALSE(sln_instance.isMatch("mississippi", "mis*is*p*."));
}