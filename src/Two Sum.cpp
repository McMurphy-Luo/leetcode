#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using std::find;
using std::map;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, vector<size_t>> numbers_map;
    for (size_t index = 0; index < nums.size(); ++index) {
      map<int, vector<size_t>>::iterator it = numbers_map.find(nums.at(index));
      if (it == numbers_map.cend()) {
        it = numbers_map.emplace(nums.at(index), vector<size_t>()).first;
      }
      it->second.push_back(index);
    }
    vector<int> result;
    for (map<int, vector<size_t>>::const_iterator it = numbers_map.cbegin(); it != numbers_map.cend(); ++it) {
      int reminder = target - it->first;
      if (reminder == it->first && it->second.size() > 1) {
        result.push_back(static_cast<int>(it->second.at(0)));
        result.push_back(static_cast<int>(it->second.at(1)));
        break;
      }
      map<int, vector<size_t>>::const_iterator reminder_in_map = numbers_map.find(reminder);
      if (reminder_in_map == numbers_map.cend()) {
        continue;
      }
      result.push_back(static_cast<int>(it->second.at(0)));
      result.push_back(static_cast<int>(reminder_in_map->second.at(0)));
      break;
    }
    return result;
  }
};

TEST_CASE("Test the solution for problem \"Two Sum\"") {
  Solution sln_instance;
  vector<int> input = { 2, 7, 11, 15 };
  vector<int> output = sln_instance.twoSum(input, 9);
  REQUIRE(output.size() == 2);
  REQUIRE(find(output.cbegin(), output.cend(), 0) != output.cend());
  REQUIRE(find(output.cbegin(), output.cend(), 1) != output.cend());
}