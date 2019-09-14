#include "catch.hpp"
#include <cstring>


namespace
{
  void reverse_string(char* begin, char* end) {

  }
}

class Solution {
public:
  int reverse(int x) {
    char buf[64];
    _itoa_s(x, buf, 10);
    int char_count_to_ignore = 0;



    while (*buf == '0') {
      ++char_count_to_ignore;
    }

    
    return 0;
  }
};

TEST_CASE("Test the solution for problem \"Reverse Integer\"") {
  Solution solution_instance;
  CHECK(solution_instance.reverse(123) == 321);
  CHECK(solution_instance.reverse(-123) == -321);
  CHECK(solution_instance.reverse(120) == 21);
}
