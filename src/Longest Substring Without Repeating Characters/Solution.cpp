#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include <string>

using std::string;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {

  }
};

TEST_CASE("Test the solution for problem 'Longest Substring Without Repeating Characters'") {
  Solution solution_instance;
  REQUIRE(solution_instance.lengthOfLongestSubstring("abcabcbb") == 3);
  REQUIRE(solution_instance.lengthOfLongestSubstring("bbbbb") == 1);
  REQUIRE(solution_instance.lengthOfLongestSubstring("pwwkew") == 3);
}