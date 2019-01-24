#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "Sort.h"

const int* test_array_0 = nullptr;
const int test_array_1[1] = {1};
const int test_array_2[2] = {10, 3};
const int test_array_3[2] = {3, 10};
const int test_array_4[4] = {6, 984311654, 30, 0};
const int test_array_5[13] = {31690, 0, 42346549, 0, 1659, 2, 689, 1, -123, 1, 1, 1239, 10};

int IntegerComparator(const int& lhs, const int& rhs) {
  if (lhs < rhs) {
    return -1;
  }
  if (lhs > rhs) {
    return 1;
  }
  return 0;
}

TEST_CASE("Test the quick sort algorithm") {
  int source[5] = {5, 12, 30, 9, 16};
  QuickSort<int*, int>(source, source + 5, IntegerComparator);
  REQUIRE(source[0] == 5);
  REQUIRE(source[1] == 9);
  REQUIRE(source[2] == 12);
  REQUIRE(source[3] == 16);
  REQUIRE(source[4] == 30);
}