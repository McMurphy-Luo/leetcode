#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::map;
using std::size_t;
using std::pair;

struct StepData {
  int border_count;
  map<int, size_t> step;
};

class Solution {
public:
  bool makesquare(vector<int> &nums) {
    StepData step_source;
    int sum = 0;
    step_source.border_count = 0;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
      ++step_source.step[*it];
      sum += *it;
    }
    int border_length = sum / 4;
    int reminder = sum % 4;
    if (reminder != 0) {
      return false;
    }
    if (border_length == 0) {
      return false;
    }
    return Iterate(step_source, border_length);
  }

  vector<map<int, size_t>> FindPosibility(const map<int, size_t>& source, int count_to_remove) {
    assert(count_to_remove != 0);
    vector<map<int, size_t>> result_of_me;
    if (source.empty()) {
      return result_of_me;
    }
    map<int, size_t> copy = source;
    pair<int, size_t> first_item_in_map = *(copy.begin());
    assert(first_item_in_map.second != 0);
    copy.erase(copy.begin());
    for (size_t item_removed_from_first_item = 0; item_removed_from_first_item <= first_item_in_map.second; ++item_removed_from_first_item) {
      int count_to_accomplished_by_others = count_to_remove - static_cast<int>(item_removed_from_first_item) * first_item_in_map.first;
      if (count_to_accomplished_by_others == 0) {
        pair<int, size_t> item_accomplish_the_job;
        item_accomplish_the_job.first = first_item_in_map.first;
        item_accomplish_the_job.second = item_removed_from_first_item;
        map<int, size_t> posibility;
        posibility.insert(item_accomplish_the_job);
        result_of_me.push_back(posibility);
      }
      if (count_to_accomplished_by_others <= 0) {
        break;
      }
      vector<map<int, size_t>> result = FindPosibility(copy, count_to_accomplished_by_others);
      pair<int, size_t> first_item;
      first_item.first = first_item_in_map.first;
      first_item.second = item_removed_from_first_item;
      for (vector<map<int, size_t>>::const_iterator it = result.begin(); it != result.end(); ++it) {
        map<int, size_t> item = *it;
        if (first_item.second != 0) {
          item.insert(first_item);
        }
        result_of_me.push_back(item);
      }
    }
    return result_of_me;
  }

  map<int, size_t> StripMap(const map<int, size_t>& lhs, const map<int, size_t>& rhs) {
    map<int, size_t> result = lhs;
    for (map<int, size_t>::const_iterator it = rhs.cbegin(); it != rhs.end(); ++it) {
      map<int, size_t>::iterator it_subtractor = result.find(it->first);
      if (it_subtractor != result.end()) {
        it_subtractor->second -= it->second;
      }
      if (it_subtractor->second == 0) {
        result.erase(it_subtractor);
      }
    }
    return result;
  }

  bool Iterate(const StepData& step_source, int border_length) {
    if (step_source.border_count == 4 && step_source.step.empty()) {
      return true;
    }
    if (step_source.border_count >= 4) {
      return false;
    }
    if (step_source.step.empty()) {
      return false;
    }
    vector<map<int, size_t>> result = FindPosibility(step_source.step, border_length);
    for (vector<map<int, size_t>>::const_iterator it = result.cbegin(); it != result.cend(); ++it) {
      StepData next_step;
      next_step.step = StripMap(step_source.step, *it);
      next_step.border_count = step_source.border_count + 1;
      if (Iterate(next_step, border_length)) {
        return true;
      }
    }
    return false;
  }
};

TEST_CASE("Test the solution for problem \"Matchsticks to Square\"") {
  Solution solution_instance;
  vector<int> case_1_input;
  case_1_input.push_back(1);
  case_1_input.push_back(1);
  case_1_input.push_back(2);
  case_1_input.push_back(2);
  case_1_input.push_back(2);
  REQUIRE(solution_instance.makesquare(case_1_input));

  vector<int> case_2_input;
  case_2_input.push_back(3);
  case_2_input.push_back(3);
  case_2_input.push_back(3);
  case_2_input.push_back(3);
  case_2_input.push_back(4);
  REQUIRE_FALSE(solution_instance.makesquare(case_2_input));
}

int main(int argc, char* argv[]) {
  int result = Catch::Session().run(argc, argv);
  cin.get();
  return result;
}