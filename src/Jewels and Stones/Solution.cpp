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
    return result;
  }
};