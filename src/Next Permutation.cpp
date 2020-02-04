#include "catch.hpp"
#include <iterator>
#include <vector>
#include <algorithm>

using std::vector;
using std::swap;
using std::reverse;
using std::advance;

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
      if (list.at(index) < list.at(static_cast<size_t>(index) + 1)) {
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
    if (nums.size() == 0) {
      return;
    }
    return PartialPermutation(nums, 0, static_cast<int>(nums.size()) - 1);
  }

  bool IsReversePermutation(const vector<int>& nums, int begin, int end) {
    if (!(begin >= 0 && end < nums.size() && end >= begin)) {
      assert(false);
      return false;
    }
  }

  void PartialPermutation(vector<int>& nums, int begin, int end) {
    if (!(begin >= 0 && end < nums.size() && end >= begin)) {
      assert(false);
      return;
    }
    if (begin == end) {
      return;
    }
    if (begin + 1 == end) {
      swap(nums[begin], nums[end]);
      return;
    }
    int index = end;
    int index_not_reverse_ordered = index - 1;
    do {
      if (nums.at(index_not_reverse_ordered) < nums.at(index)) {
        break;
      }
      --index;
      --index_not_reverse_ordered;
    } while (index > begin);
    if (index == begin) {
      vector<int>::iterator reverse_vertex_begin = nums.begin();
      advance(reverse_vertex_begin, begin);
      vector<int>::iterator reverse_vertex_end = nums.begin();
      advance(reverse_vertex_end, end + 1);
      reverse(reverse_vertex_begin, reverse_vertex_end);
      return;
    }
    assert(index_not_reverse_ordered >= begin);
    assert(nums.at(index_not_reverse_ordered) < nums.at(index));
    
    int next_index = end;
    while (nums.at(next_index) <= nums.at(index_not_reverse_ordered)) {
      --next_index;
    }
    swap(nums[next_index], nums[index_not_reverse_ordered]);
    vector<int>::iterator reverse_vertex_begin = nums.begin();
    advance(reverse_vertex_begin, index);
    vector<int>::iterator reverse_vertex_end = nums.begin();
    advance(reverse_vertex_end, end + 1);
    reverse(reverse_vertex_begin, reverse_vertex_end);
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
