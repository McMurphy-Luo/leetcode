#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include <vector>
#include <cassert>

using namespace std;

struct Accumulation {
  int total;
  int contains_last;
};



class Solution {
public:
  int rob(vector<int>& nums) {
    vector<Accumulation> result = AccumulateTotalNumber(nums);
    if (result.empty()) {
      return 0;
    }
    return result.back().total;
  }

  vector<Accumulation> AccumulateTotalNumber(vector<int> numbers) {
    if (numbers.empty()) {
      return vector<Accumulation>();
    }
    if (numbers.size() == 1) {
      Accumulation the_first_one;
      the_first_one.total = numbers[0];
      the_first_one.contains_last = true;
      vector<Accumulation> result;
      result.push_back(the_first_one);
      return result;
    }

    vector<int> number_slice(numbers.begin(), numbers.end() - 1);
    int last_value = numbers.back();

    

    vector<Accumulation> previous_step = AccumulateTotalNumber(number_slice);

	std::cout << previous_step.back().total << std::endl;


    Accumulation last;
    assert(previous_step.size() >= 1);
    if (previous_step.back().contains_last) {
      Accumulation the_item_before_last;
      the_item_before_last.contains_last = false;
      the_item_before_last.total = 0;
      if (previous_step.size() >= 2) {
        the_item_before_last = previous_step[previous_step.size() - 2];
      }
      if ((the_item_before_last.total + last_value) > previous_step.back().total) {
        last.contains_last = true;
        last.total = the_item_before_last.total + last_value;
      } else {
        last.contains_last = false;
        last.total = previous_step.back().total;
      }
    } else {
      Accumulation last;
      last.contains_last = true;
      last.total = previous_step.back().total + last_value;
    }
    previous_step.push_back(last);
    return previous_step;
  }
};

TEST_CASE("Test the House Robber problem") {
  Solution test_instance;
  vector<int> case_1 = {1, 2, 3, 1};
  REQUIRE(test_instance.rob(case_1) == 4);

  vector<int> case_2 = {2, 7, 9, 3, 1};
  REQUIRE(test_instance.rob(case_2) == 12);
}

int main(int argc, char* argv[]) {
  int result = Catch::Session().run(argc, argv);
  cin.get();
  return result;
}