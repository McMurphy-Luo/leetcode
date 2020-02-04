#include "catch.hpp"
#include <cstring>
#include <cstdio>
#include <sstream>

using std::swap;
using std::snprintf;

namespace
{
  void reverse_string(char* begin, char* end) {
    while (begin < end) {
      swap(*begin, *end);
      ++begin;
      --end;
    }
  }
}

class Solution {
public:
  int reverse(int x) {
    char buf[64];
    memset(buf, 0, sizeof(buf));
    int return_val = snprintf(buf, sizeof(buf), "%d", x);
    if (return_val != -1) {
      bool negtive = (buf[0] == '-');
      reverse_string(buf + (negtive ? 1 : 0), buf + strnlen(buf, sizeof(buf)) - 1);
      int char_count_to_ignore = negtive ? 1 : 0;
      while (*(buf + char_count_to_ignore) == '0') {
        ++char_count_to_ignore;
      }
      long long result = atoll(buf + char_count_to_ignore)* (negtive ? -1 : 1);
      if (result >= INT_MAX || result <= INT_MIN) {
        return 0;
      }
      else {
        return static_cast<int>(result);
      }
    }
    else {
      return 0;
    }
  }
};

TEST_CASE("Test the solution for problem \"Reverse Integer\"") {
  Solution solution_instance;
  CHECK(solution_instance.reverse(123) == 321);
  CHECK(solution_instance.reverse(-123) == -321);
  CHECK(solution_instance.reverse(120) == 21);
  CHECK(solution_instance.reverse(1534236469) == 0);
}
