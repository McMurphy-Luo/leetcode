#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>
#include <vector>

using std::string;
using std::deque;
using std::vector;

struct Palindrome {
  size_t begin;
  size_t end;
};

class Solution {
public:
  string longestPalindrome(string s) {
    
  }
};

TEST_CASE("Test the solution for problem 'Longest Palindromic Substring'") {
  string input_1 = "babad";
  string output_1_1 = "bab";
  string output_1_2 = "aba";
  string input_2 = "cbbd";
  string output_2 = "bb";
  Solution sln_instance;
  string output_1 = sln_instance.longestPalindrome(input_1);
  CHECK(output_1 == output_1_1 || output_1 == output_1_2);
  CHECK(sln_instance.longestPalindrome(input_2) == output_2);
}
