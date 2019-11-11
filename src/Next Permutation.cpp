#include "catch.hpp"
#include <iterator>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;
using std::advance;
using std::sort;

namespace
{
  template<typename T>
  bool VectorEquals(const vector<T> lhs, const vector<T> rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (int i = 0; i < lhs.size(); ++i) {
      if (lhs.at(i) != rhs.at(i)) {
        return false;
      }
    }
    return true;
  }

  bool IsReverseOrder(const vector<int>& list, int begin, int end) {
    if (begin == end) {
      return true;
    }
    assert(end > begin);
    for (int index = begin; index + 1 <= end; ++index) {
      if (list.at(index) < list.at(index + 1)) {
        return false;
      }
    }
    return true;
  }

  int FindNext(const vector<int>& list, int begin, int end, int target) {
    int current = end;
    while (list.at(current) <= target && current > begin) {
      --current;
    }
    return current;
  }
}

class Solution {
public:
  void nextPermutation(vector<int>& nums) {
    return PartialPermutation(nums, 0, nums.size() - 1);
  }

  void PartialPermutation(vector<int>& nums, int begin, int end) {
    int index = begin;
    int index_unordered = index + 1;
    for (; index <= end; ++index) {
      index_unordered = index + 1;
      if (index == end) {
        break;
      }
      if (nums.at(index) > nums.at(index_unordered)) {
        index_unordered = index;
        break;
      }
    }
    if (index == end) {
      if (end - begin > 0) {
        swap(nums[end], nums[end - 1]);
      }
      return;
    }
    assert(index >= begin && index + 1 <= end);
    if (!IsReverseOrder(nums, index_unordered, end)) {
      return PartialPermutation(nums, index_unordered, end);
    }
    if (index_unordered > begin) {
      int previous_maybe_reverse_ordered = index_unordered - 1;
      while (previous_maybe_reverse_ordered >= begin) {
        if (nums.at(previous_maybe_reverse_ordered) > nums.at(index_unordered)) {
          index_unordered = previous_maybe_reverse_ordered;
          previous_maybe_reverse_ordered = index_unordered - 1;
        }
        else {
          break;
        }
      }
    }
    if (index_unordered == begin) {
      for (int index = 0; begin + index < end - index; ++index) {
        swap(nums[begin + index], nums[end - index]);
      }
    }
    else {
      swap(nums[FindNext(nums, index_unordered, end, nums.at(index_unordered - 1))], nums[index_unordered - 1]);
    }
    sort(nums.begin() + index_unordered, nums.begin() + end + 1);
  }
};

TEST_CASE("Test the solution for problem 'Next Permutation'") {
  Solution sln_instance;
  vector<int> permutation_1 = { 1, 2, 3 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 1, 3, 2 }));
  permutation_1 = { 3, 2, 1 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 1, 2, 3 }));
  permutation_1 = { 1, 1, 5 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 1, 5, 1 }));
  permutation_1 = { 1, 3, 2 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 2, 1, 3 }));
  permutation_1 = { 2, 3, 1 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 3 ,1, 2 }));
  permutation_1 = { 1, 5, 1 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 5, 1, 1 }));
  permutation_1 = { 4, 2, 4, 4, 3 };
  sln_instance.nextPermutation(permutation_1);
  CHECK(VectorEquals(permutation_1, { 4, 3, 2, 4, 4 }));
}
