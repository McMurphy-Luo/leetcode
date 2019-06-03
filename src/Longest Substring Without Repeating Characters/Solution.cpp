#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include <string>
#include <map>

using std::string;
using std::map;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    map<char, size_t> unique_char_position;
    int total_count = 0;
    for (size_t i = 0; i < s.size(); ++i) {
      char current = s.at(i);
      map<char, size_t>::const_iterator char_in_map = unique_char_position.find(current);
      if (char_in_map == unique_char_position.cend()) {
        unique_char_position.emplace(std::make_pair(current, i));
      }
    }
    return total_count;
  }
};

TEST_CASE("Test the solution for problem 'Longest Substring Without Repeating Characters'") {
  Solution solution_instance;
  REQUIRE(solution_instance.lengthOfLongestSubstring("abcabcbb") == 3);
  REQUIRE(solution_instance.lengthOfLongestSubstring("bbbbb") == 1);
  REQUIRE(solution_instance.lengthOfLongestSubstring("pwwkew") == 3);
}