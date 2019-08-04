#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;
using std::sort;

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> output;
    return DigitsToString(digits, output);
  }

  vector<char> DigitToChar(char digit) {
    if (digit == '2') {
      return { 'a', 'b', 'c' };
    }
    if (digit == '3') {
      return { 'd', 'e', 'f' };
    }
    if (digit == '4') {
      return { 'g', 'h', 'i' };
    }
    if (digit == '5') {
      return { 'j', 'k', 'l' };
    }
    if (digit == '6') {
      return { 'm', 'n', 'o' };
    }
    if (digit == '7') {
      return { 'p', 'q', 'r', 's' };
    }
    if (digit == '8') {
      return { 't', 'u', 'v' };
    }
    if (digit == '9') {
      return { 'w', 'x', 'y', 'z' };
    }
    return {};
  }

  vector<string> DigitsToString(const string& digits, const vector<string>& input) {
    if (digits.empty()) {
      return input;
    }
    char the_first_char = digits.front();
    vector<char> chars_to_be_appended = DigitToChar(the_first_char);
    vector<string> output;
    for (vector<char>::const_iterator it_chars = chars_to_be_appended.cbegin(); it_chars != chars_to_be_appended.cend(); ++it_chars) {
      if (input.empty()) {
        output.push_back(string(1, *it_chars));
      }
      else {
        for (vector<string>::const_iterator it_strings = input.cbegin(); it_strings != input.cend(); ++it_strings) {
          output.push_back(*it_strings + *it_chars);
        }
      }
    }
    return DigitsToString(digits.substr(1, string::npos), output);
  }
};

bool UnorderedArrayEqual(const vector<string>& input_1, const vector<string>& input_2) {
  if (input_1.size() != input_2.size()) {
    return false;
  }
  vector<string> input_1_copy = input_1;
  vector<string> input_2_copy = input_2;
  sort(input_1_copy.begin(), input_1_copy.end());
  sort(input_2_copy.begin(), input_2_copy.end());
  for (size_t index = 0; index < input_1_copy.size(); ++index) {
    if (input_1_copy.at(index) != input_2_copy.at(index)) {
      return false;
    }
  }
  return true;
}

TEST_CASE("Test the solution for problem \"Letter Combinations of a Phone Number\"") {
  Solution sln_instance;
  vector<string> result = sln_instance.letterCombinations("23");
  CHECK(UnorderedArrayEqual(result, vector<string>{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
}
