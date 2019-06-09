#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <vector>
#include <algorithm>

using std::vector;
using std::merge;
using std::back_inserter;

/**
 * Note, this solution use brute force algorithm to find the median of two sorted arrays.
 * The time complexity and space complexity may not meet the requirement of leetcode problem number 4.
 * McMurphy.Luo: Sometimes, when I implement algorithm, I don't take much care about
 * the time complexity and space complexity as long as its not exceed O(n^2). I would rather
 * implement in a clear, easy to maintained way.
 */
class Solution {
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int> merged;
    merge(nums1.cbegin(), nums1.cend(), nums2.cbegin(), nums2.cend(), back_inserter(merged));
    assert(merged.size() == (nums1.size() + nums2.size()));
    if (merged.size() % 2 == 0) {
      return (static_cast<double>(merged.at(merged.size() / 2 - 1)) + static_cast<double>(merged.at(merged.size() / 2))) / 2;
    }
    else {
      return merged.at(merged.size() / 2);
    }
  }
};

TEST_CASE("Test the solution for problem 'Median of Two Sorted Arrays'") {
  Solution solution_instance;

  vector<int> input_1_1 = { 1, 3 };
  vector<int> input_1_2 = { 2 };
  CHECK(solution_instance.findMedianSortedArrays(input_1_1, input_1_2) == Approx(2.0));

  vector<int> input_2_1 = { 1, 2 };
  vector<int> input_2_2 = { 3, 4 };
  CHECK(solution_instance.findMedianSortedArrays(input_2_1, input_2_2) == Approx(2.5));
}