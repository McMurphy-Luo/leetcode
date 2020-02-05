#include "catch.hpp"
#include <vector>

using std::vector;
using std::min;
using std::max;

struct Wave {
  int value;
  int index;
};

class Solution {
  vector<Wave> Analyze(const vector<int>& input) {
    Wave this_point;
    vector<Wave> result;
    for (
      size_t index = 0;
      index < input.size();
      ++index
    ) {
      this_point.value = input.at(index);
      this_point.index = static_cast<int>(index);
      bool is_wave = false;
      if (index == 0) {
        if (index + 1 < input.size()) {
          is_wave = input.at(index + 1) < this_point.value;
        }
      } else if (index == input.size() - 1) {
        if (index - 1 >= 0) {
          is_wave = input.at(index - 1) < this_point.value;
        }
      }
      else {
        assert(index > 0 && index < input.size());
        is_wave =
          input.at(index - 1) < this_point.value && input.at(index + 1) <= this_point.value
          ||
          input.at(index - 1) <= this_point.value && input.at(index + 1) <= this_point.value;
      }
      if (is_wave) {
        result.push_back(this_point);
      }
    }
    vector<Wave>::iterator it = result.begin();

    while (it != result.end()) {
      if (it == result.begin()) {
        ++it;
        continue;
      }
      vector<Wave>::iterator previous = result.begin();
      bool has_left_higher = false;
      while (previous != it) {
        if (previous->value > it->value) {
          has_left_higher = true;
          break;
        }
        ++previous;
      }
      bool has_right_higher = false;
      vector<Wave>::iterator next = it + 1;
      while (next != result.end()) {
        if (next->value > it->value) {
          has_right_higher = true;
          break;
        }
        ++next;
      }
      if (has_left_higher && has_right_higher) {
        it = result.erase(it);
      }
      else {
        ++it;
      }
    }
    return result;
  }

public:
  int trap(vector<int>& height) {
    vector<Wave> result = Analyze(height);
    int total = 0;
    for (
      vector<Wave>::iterator it = result.begin();
      it != result.end();
      ++it
    ) {
      if (it == result.begin()) {
        continue;
      }
      vector<Wave>::iterator previous = it - 1;
      int container_height = min(previous->value, it->value);
      for (int index = previous->index + 1; index < it->index; ++index) {
        total += max(0, container_height - height.at(index));
      }
    }
    return total;
  }
};

TEST_CASE("Test the solution for problem \"Trapping Rain Water\"") {
  Solution sln_instance;
  vector<int> input{ 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
  CHECK(sln_instance.trap(input) == 6);
  input = { 5,4,1,2 };
  CHECK(sln_instance.trap(input) == 1);
  input = { 6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3 };
  CHECK(sln_instance.trap(input) == 83);
}
