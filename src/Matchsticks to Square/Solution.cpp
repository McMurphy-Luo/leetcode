#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using std::vector;
using std::cin;
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
    step_source.border_count = 0;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
      ++step_source.step[*it];
    }
    vector<map<int, size_t>> posibilities = EnumeratePosibilities(step_source.step);
    if (posibilities.empty()) {
      return false;
    }
    return Iterate(step_source, );
  }

  vector<map<int, size_t>> EnumeratePosibilities(const map<int, size_t>& source) {
    int sum = 0;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
      sum += *it;
    }
    int border_length = sum / 4;
    int remainder = sum % 4;
    if (border_length <= 0 || remainder != 0) {
      return false;
    }
  }

  pair<bool, map<int, size_t>> FindPosibility(const map<int, size_t>& source, int count_to_remove) {
    assert(count_to_remove != 0);
    map<int, size_t> copy = source;
    pair<bool, map<int, size_t>> result;
    if (copy.empty()) {
      result.first = false;
      return result;
    }
    copy.erase(copy.begin());
    pair<bool, map<int, size_t>> result = FindPosibility(copy, count_to_remove);
    


  }

  map<int, size_t> StripItem(const map<int, size_t>& source) {

  }

  pair<bool, map<int, size_t>> SubtractMap(const map<int, size_t>& minuend, const map<int, size_t>& subtrahend) {
    map<int, size_t> result;
    for (map<int, size_t>::const_iterator it = subtrahend.cbegin(); it != subtrahend.cend(); ++it) {
      if (minuend.)

    }
  }

  bool Iterate(const StepData& step_source) {
    if (step_source.border_count == 4 && step_source.step.empty()) {
      return true;
    }
    if (step_source.border_count >= 4) {
      return false;
    }
    if (step_source.step.empty()) {
      return false;
    }
    vector<StepData> result = RetrieveBorder(step_source);
    for (vector<StepData>::iterator it = result.begin(); it != result.end(); ++it) {
      if (Iterate(*it)) {
        return true;
      }
    }
    return false;
  }

  vector<StepData> RetrieveBorder(const StepData& step_source) {
    vector<StepData> result;

    
    

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