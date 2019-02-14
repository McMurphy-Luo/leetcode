#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include <vector>
#include <iostream>
#include <map>

using std::vector;
using std::cin;
using std::map;
using std::size_t;
using std::pair;

class Solution {
public:
  bool makesquare(vector<int> &nums) {
    map<int, size_t> step_source;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it) {
      ++step_source[*it];
    }

    vector<map<int, size_t>> after_step_result;
    after_step_result = RetrieveBorder(step_source);

    
    if (!Step1(before_step, after_step)) {
      return false;
    }

    if (!Step2(after_step1))
  }

  bool Iterate*() {
    
  }


  vector<map<int, size_t>> RetrieveBorder(map<int, size_t>& step_source) {

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