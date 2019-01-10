#include <string>

using std::string;

class Solution {
public:
  string convertToTitle(int n) {
    string result;

    int reminder = 0;
    int quotient = n - 1;

    if (quotient == 0) {
      result.push_back('A');
    }

    while (quotient > 0) {
      reminder = n % 26;
      quotient = quotient / 26;
      char next_char = reminder + 'A';
      result.push_back(next_char);
    }
    
    return result;
  }
};