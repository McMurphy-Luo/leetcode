#define CATCH_CONFIG_MAIN
#include "../catch.hpp"

#include <string>
#include <map>
#include <algorithm>

using std::string;
using std::map;
using std::max;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    size_t begin = 0;
    size_t end = begin;
    size_t total_count = 0;
    if (s.size() == 1) {
      return 1;
    }
    while (end < s.size()) {
      char current = s.at(end);
      bool find_duplicated = false;
      for (size_t i = begin; i < end; ++i) {
        if (s.at(i) == current) {
          total_count = max(total_count, end - begin);
          begin = i + 1;
          find_duplicated = true;
          break;
        }
      }
      if (!find_duplicated) {
        total_count = max(total_count, end - begin + 1);
      }
      ++end;
    }
    return static_cast<int>(total_count);
  }
};

TEST_CASE("Test the solution for problem 'Longest Substring Without Repeating Characters'") {
  Solution solution_instance;
  REQUIRE(solution_instance.lengthOfLongestSubstring("abcabcbb") == 3);
  REQUIRE(solution_instance.lengthOfLongestSubstring("bbbbb") == 1);
  REQUIRE(solution_instance.lengthOfLongestSubstring("pwwkew") == 3);
  REQUIRE(solution_instance.lengthOfLongestSubstring("au") == 2);
}