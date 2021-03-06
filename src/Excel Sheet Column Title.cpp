#include "catch.hpp"
#include <string>
#include <algorithm>
#include <iostream>

using std::string;
using std::cin;
using std::reverse;

class Solution {
public:
  string convertToTitle(int n) {
    int reserved = n;
    int quotient = 0;
    string result;
    while (reserved > 0) {
      quotient = reserved % 26;
      reserved = reserved / 26;

      if (quotient == 0 && reserved > 0) {
        reserved = reserved - 1;
        quotient = 26;
      }
      result.push_back(quotient - 1 + 'A');
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

TEST_CASE("Test the solution for problem 'Excel Sheet Column Title'") {
  Solution test_instance;
  REQUIRE(test_instance.convertToTitle(1) == "A");
  REQUIRE(test_instance.convertToTitle(26) == "Z");
  REQUIRE(test_instance.convertToTitle(27) == "AA");
  REQUIRE(test_instance.convertToTitle(26 * 26) == "YZ");
}
