#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Palindrome {
  size_t begin;
  size_t end;
  Palindrome()
    : begin(0)
    , end(0) {

  }
};

class Solution {
public:
  string longestPalindrome(string s) {
    vector<Palindrome> palindromes_found;
    for (size_t i = 0; i < s.size(); ++i) {
      Palindrome one_item_found;
      one_item_found.begin = i;
      one_item_found.end = i;
      palindromes_found.push_back(one_item_found);
      if ((i + 1) < s.size() && s.at(i) == s.at(i + 1)) {
        one_item_found.begin = i;
        one_item_found.end = i + 1;
        palindromes_found.push_back(one_item_found);
      }
    }
    Palindrome longest_pralindrome;
    longest_pralindrome.begin = 0;
    longest_pralindrome.end = 0;
    for (
      vector<Palindrome>::const_iterator it = palindromes_found.begin();
      it != palindromes_found.end();
      ++it
      ) {
      Palindrome item = *it;
      assert(item.begin == item.end || (item.end - item.begin) == 1);
      size_t half_palindrome_length = 0;
      while (true) {
        if (
          item.begin < half_palindrome_length
          ||
          item.end + half_palindrome_length >= s.size()
        ) {
          --half_palindrome_length;
          break;
        }
        if (s.at(item.begin - half_palindrome_length) != s.at(item.end + half_palindrome_length)) {
          --half_palindrome_length;
          break;
        }
        ++half_palindrome_length;
      }
      if ((longest_pralindrome.end - longest_pralindrome.begin) < (item.end - item.begin + 2 * half_palindrome_length)) {
        longest_pralindrome.end = item.end + half_palindrome_length;
        longest_pralindrome.begin = item.begin - half_palindrome_length;
      }
    }
    return s.substr(longest_pralindrome.begin, longest_pralindrome.end - longest_pralindrome.begin + 1);
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
  CHECK((output_1 == output_1_1 || output_1 == output_1_2));
  CHECK(sln_instance.longestPalindrome(input_2) == output_2);
}
