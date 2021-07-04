#include <algorithm>

class Solution {
public:
  int uniquePaths(int m, int n) {
    return static_cast<int>(Factorial(std::max(m - 1, n - 1) + 1, m - 1 + n - 1) / Factorial(1, std::min(m - 1, n - 1)));
  }

  long long Factorial(long long start, long long end) {
    long long result = 1;
    while (start <= end) {
      result = result * start;
      ++start;
    }
    return result;
  }
};
