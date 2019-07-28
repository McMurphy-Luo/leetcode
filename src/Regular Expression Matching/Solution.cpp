/**
 * @author McMurphy.Luo
 * @date June/30/2019
 * @brief The solution for problem https://leetcode.com/problems/regular-expression-matching/
 */

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>

using std::string;

class Pattern {
public:
  Pattern(char state_char, bool is_any, bool is_repeat)
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

  bool Match(char value) {
    return Any() || value == Value();
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

  void SetNext(Pattern* next) {
    next_ = next;
  }

  Pattern* Next() const {
    return next_;
  }

private:
  char state_char_;
  bool is_any_;
  bool is_repeat_;
  Pattern* next_;
};

Pattern* ParsePattern(const string& pattern) {
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
  Pattern* current_state = new Pattern(current_char, is_any, is_repeat);
  Pattern* next_pattern = ParsePattern(pattern.substr(is_repeat ? 2 : 1));
  current_state->SetNext(next_pattern);
  return current_state;
}

bool RunPattern(Pattern* pattern, const string& string_to_match) {
  if (!pattern) {
    return string_to_match.empty();
  }
  assert(pattern);
  if (!pattern->Repeat()) {
    if (string_to_match.empty()) {
      return false;
    }
    assert(!string_to_match.empty());
    if (!pattern->Match(string_to_match.front())) {
      return false;
    }
    return RunPattern(pattern->Next(), string_to_match.substr(1, string::npos));
  }

  int index = 0;
  for (; index < string_to_match.size(); ++index) {
    if (!pattern->Match(string_to_match.at(index))) {
      break;
    }
  }

  while (index >= 0) {
    if (!RunPattern(pattern->Next(), string_to_match.substr(index, string::npos))) {
      --index;
    }
    else {
      break;
    }
  }
  return index >= 0;
}

void DeletePattern(Pattern* pattern) {
  if (pattern) {
    Pattern* next = pattern->Next();
    delete pattern;
    DeletePattern(next);
  }
}

class Solution {
public:
  bool isMatch(string s, string p) {
    Pattern* pattern = ParsePattern(p);
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
  CHECK_FALSE(sln_instance.isMatch("a", "ab*a"));
  CHECK(sln_instance.isMatch("", "c*c*"));
}