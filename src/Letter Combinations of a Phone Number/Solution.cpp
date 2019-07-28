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
