#include <functional>

template<typename I, typename V>
void QuickSort(I begin, I end, std::function<int(const V&, const V&)> comparator) {
  I anchor = begin;
  while(anchor < end) {
    if (*anchor < *begin) {
      std::swap(*anchor, *begin);
      ++anchor;
    }
  }

  

}