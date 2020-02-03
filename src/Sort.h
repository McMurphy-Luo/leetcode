#include <functional>
#include <cassert>

__inline int IntComparator(const int& lhs, const int& rhs) {
  if (lhs < rhs) {
    return -1;
  }
  else if (lhs > rhs) {
    return 1;
  }
  return 0;
}

template<typename I, typename V>
bool ArrayEquals(I begin_1, I end_1, I begin_2, I end_2, std::function<int(const V&, const V&)> comparator) {
  assert(begin_1 < end_1);
  assert(begin_2 < end_2);
  assert(end_1 - begin_1 == end_2 - begin_2);

  I current_1 = begin_1;
  I current_2 = begin_2;

  while (current_1 < end_1) {
    if (comparator(*current_1, *current_2) != 0) {
      return false;
    }
    ++current_1;
    ++current_2;
  }
  return true;
}

template<typename I, typename V>
void QuickSort(I begin, I end, std::function<int(const V&, const V&)> comparator) {
  assert(begin <= end);
  if (begin == end) {
    return;
  }
  I anchor_left = begin;
  I anchor_right = end - 1;
  I pivot_position = begin;
  V pivot = *begin;

  while (anchor_left != anchor_right) {
    while (anchor_left != anchor_right) {
      if (comparator(*anchor_right, pivot)) {
        std::swap(*anchor_right, *pivot_position);
        pivot_position = anchor_right;
        break;
      }
      --anchor_right;
    }
    while (anchor_left != anchor_right){
      if (comparator(pivot, *anchor_left)) {
        std::swap(*anchor_left, *pivot_position);
        pivot_position = anchor_left;
        break;
      }
      ++anchor_left;
    }
  }

  QuickSort<I, V>(begin, pivot_position, comparator);
  QuickSort<I, V>(pivot_position + 1, end, comparator);
}