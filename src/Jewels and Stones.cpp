#include "catch.hpp"
#include <string>

using std::string;

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    int character_existence_map[sizeof(char) * 256];
    memset(character_existence_map, 0, sizeof(character_existence_map));
    for (const char& character : J) {
      character_existence_map[(unsigned char)character] = 1;
    }

    size_t result = 0;
    for (const char& character : S) {
      if (character_existence_map[(unsigned char)character]) {
        result++;
      }
    }
    return static_cast<int>(result);
  }
};

TEST_CASE("Test the solution for problem \"Jewels and Stones\"") {
  Solution solution;
  REQUIRE(solution.numJewelsInStones("aA", "aAAbbbb") == 3);
  REQUIRE(solution.numJewelsInStones("z", "ZZ") == 0);
}