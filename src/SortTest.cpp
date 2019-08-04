#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include "catch.hpp"
#include "Sort.h"

using std::array;
using std::sort;
using std::copy;
using std::begin;
using std::end;
using std::function;

bool IntegerComparator(const int& lhs, const int& rhs) {
  return lhs < rhs;
}

template<typename T, size_t size>
bool ArrayQuickSorted(array<T, size> source, function<bool(const T&, const T&)> comparator) {
  array<T, size> source_copy_1 = source;
  array<T, size> source_copy_2 = source;

  QuickSort<array<T, size>::iterator, T>(source_copy_1.begin(), source_copy_1.end(), comparator);
  sort(source_copy_2.begin(), source_copy_2.end(), IntegerComparator);
  return ArrayEquals<array<T, size>::iterator, T>(source_copy_1.begin(), source_copy_1.end(), source_copy_2.begin(), source_copy_2.end(), comparator);
}

TEST_CASE("Test the quick sort algorithm") {
  REQUIRE(ArrayQuickSorted<int, 1>({1}, IntegerComparator));
  REQUIRE(ArrayQuickSorted<int, 2>({10, 3}, IntegerComparator));
  REQUIRE(ArrayQuickSorted<int, 2>({3, 10}, IntegerComparator));
  REQUIRE(ArrayQuickSorted<int, 4>({6, 984311654, 30, 0}, IntegerComparator));
  REQUIRE(ArrayQuickSorted<int, 13>({31690, 0, 42346549, 0, 1659, 2, 689, 1, -123, 1, 1, 1239, 10}, IntegerComparator));
}