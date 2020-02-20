#include "catch.hpp"
#include <vector>

using std::vector;

class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) {
      return;
    }
    RecursiveRotate(matrix, 0, static_cast<int>(matrix.size() - 1));
  }

  void RecursiveRotate(vector<vector<int>>& matrix, int begin, int end) {
    if (end <= begin) {
      return;
    }
    int x_1 = begin;
    int y_1 = begin;
    int x_2 = end;
    int y_2 = begin;
    int x_3 = end;
    int y_3 = end;
    int x_4 = begin;
    int y_4 = end;
    while (x_2 > x_1) {
      Swap(matrix, x_1, y_1, x_2, y_2, x_3, y_3, x_4, y_4);
      ++x_1;
      ++y_2;
      --x_3;
      --y_4;
    }
    RecursiveRotate(matrix, begin + 1, end - 1);
  }

  void Swap(vector<vector<int>>& matrix, int x_1, int y_1, int x_2, int y_2, int x_3, int y_3, int x_4, int y_4) {
    int temp = matrix[y_1][x_1];
    matrix[y_1][x_1] = matrix[y_4][x_4];
    matrix[y_4][x_4] = matrix[y_3][x_3];
    matrix[y_3][x_3] = matrix[y_2][x_2];
    matrix[y_2][x_2] = temp;
  }
};

namespace
{
  bool ArrayEquals(const vector<int>& lhs, const vector<int>& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (size_t index = 0; index < lhs.size(); ++index) {
      if (lhs.at(index) != rhs.at(index)) {
        return false;
      }
    }
    return true;
  }

  bool ArrayOfArrayEquals(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (size_t index = 0; index < lhs.size(); ++index) {
      if (!ArrayEquals(lhs.at(index), rhs.at(index))) {
        return false;
      }
    }
    return true;
  }
}

TEST_CASE("Test the solution for problem \"\"") {
  vector<vector<int>> input{
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 }
  };
  vector<vector<int>> expected_output{
    { 7,4,1 },
    { 8,5,2 },
    { 9,6,3 }
  };

  Solution sln_instance;
  sln_instance.rotate(input);
  CHECK(ArrayOfArrayEquals(input, expected_output));
  input = {
    { 5, 1, 9, 11 },
    { 2, 4, 8, 10 },
    { 13, 3, 6, 7 },
    { 15, 14, 12, 16 }
  };
  expected_output = {
    { 15,13, 2, 5 },
    { 14, 3, 4, 1 },
    { 12, 6, 8, 9 },
    { 16, 7,10,11 }
  };
  sln_instance.rotate(input);
  CHECK(ArrayOfArrayEquals(input, expected_output));
}