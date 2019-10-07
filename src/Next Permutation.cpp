#include "catch.hpp"
#include <vector>

using std::vector;

namespace
{
  template<typename T>
  bool VectorEquals(const vector<T> lhs, const vector<T> rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (size_t i = 0; i < lhs.size(); ++i) {
      if (lhs.at(i) != rhs.at(i)) {
        return false;
      }
    }
    return true;
  }
}

class Solution {
public:
  void nextPermutation(vector<int>& nums) {

  }
};

TEST_CASE("Test the solution for problem 'Next Permutation'") {
  Solution sln_instance;
  vector<int> permutation_1 = { 1, 2, 3 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 1, 3, 2 }));
  permutation_1 = { 3, 2, 1 };
  CHECK(VectorEquals(permutation_1, { 1, 2, 3 }));
  permutation_1 = { 1, 1, 5 };
  CHECK(VectorEquals(permutation_1, { 1, 5, 1 }));
}