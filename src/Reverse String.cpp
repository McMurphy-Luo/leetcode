#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  void reverseString(vector<char>& s)
  {
    if (s.size() <= 1) {
      return;
    }
    for (size_t i = 0; i < s.size() / 2; ++i) {
      char val = s.at(i);
      s[i] = s[s.size() - 1 - i];
      s[s.size() - i - 1] = val;
    }
  }
};

template<typename T>
bool VectorEqual(const vector<T>& lhs, const vector<T>& rhs) {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  for (size_t i = 0; i < lhs.size(); ++i) {
    if (lhs.at(i) != rhs.at(i)) {
      return false;
    }
  }
  return true;
}

TEST_CASE("Test the solution for problem \"Reverse String\"") {
  vector<char> case_1_input = { 'H', 'a', 'n', 'n', 'a', 'h' };
  vector<char> case_1_output = { 'h', 'a', 'n', 'n', 'a', 'H' };
  vector<char> case_2_input = { 'h', 'e', 'l', 'l', 'o' };
  vector<char> case_2_output = { 'o', 'l', 'l', 'e', 'h' };
  vector<char> case_3_input = { 'A', ' ', 'm', 'a', 'n', ',', ' ', 'a', ' ', 'p', 'l', 'a', 'n', ',', ' ', 'a', ' ', 'c', 'a', 'n', 'a', 'l', ':', ' ', 'P', 'a', 'n', 'a', 'm', 'a' };
  vector<char> case_3_output = { 'a', 'm', 'a', 'n', 'a', 'P', ' ', ':', 'l', 'a', 'n', 'a', 'c', ' ', 'a', ' ', ',', 'n', 'a', 'l', 'p', ' ', 'a', ' ', ',', 'n', 'a', 'm', ' ', 'A' };
  Solution solution_instance;
  solution_instance.reverseString(case_1_input);
  solution_instance.reverseString(case_2_input);
  solution_instance.reverseString(case_3_input);
  REQUIRE(VectorEqual(case_1_input, case_1_output));
  REQUIRE(VectorEqual(case_2_input, case_2_output));
  REQUIRE(VectorEqual(case_3_input, case_3_output));
}
