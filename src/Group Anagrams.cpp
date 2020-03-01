#include "catch.hpp"
#include <vector>
#include <algorithm>
#include <map>

using std::vector;
using std::string;
using std::find;
using std::find_if;
using std::sort;
using std::map;
using std::pair;
using std::transform;
using std::back_inserter;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string> copy = strs;
    for (vector<string>::iterator it = copy.begin(); it != copy.end(); ++it) {
      sort(it->begin(), it->end());
    }
    map<string, vector<string>> anagram_strings;
    for (size_t i = 0; i < copy.size(); ++i) {
      map<string, vector<string>>::iterator pos = anagram_strings.find(copy.at(i));
      if (pos == anagram_strings.end()) {
        pos = anagram_strings.emplace(copy.at(i), vector<string>()).first;
      }
      pos->second.push_back(strs.at(i));
    }
    vector<vector<string>> result;
    transform(anagram_strings.cbegin(), anagram_strings.cend(), back_inserter(result), [](const pair<string, vector<string>>& item) -> vector<string> {
      return item.second;
    });
    return result;
  }
};

namespace
{
  bool ArrayOfStringSame(const vector<string>& lhs, const vector<string>& rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (vector<string>::const_iterator it = lhs.cbegin(); it != lhs.cend(); ++it) {
      if (find(rhs.cbegin(), rhs.cend(), *it) == rhs.cend()) {
        return false;
      }
    }
    return true;
  }

  bool SameAnagramsGroups(const vector<vector<string>>& lhs, const vector<vector<string>> rhs) {
    if (lhs.size() != rhs.size()) {
      return false;
    }
    for (vector<vector<string>>::const_iterator it = lhs.cbegin(); it != lhs.cend(); ++it) {
      const vector<string>& item_want_to_find = *it;
      if (find_if(rhs.cbegin(), rhs.cend(), [&item_want_to_find](const vector<string>& item) -> bool {
        return ArrayOfStringSame(item, item_want_to_find);
        }) == rhs.cend()) {
        return false;
      }
    }
    return true;
  }
}

TEST_CASE("Test the solution for problem \"Group Anagrams\"") {
  Solution sln_instance;
  vector<vector<string>> expected_output{
    { "ate", "eat", "tea" },
    { "nat", "tan" },
    { "bat" }
  };
  vector<string> input {
    "eat", "tea", "tan", "ate", "nat", "bat"
  };
  vector<vector<string>> output = sln_instance.groupAnagrams(input);
  CHECK(SameAnagramsGroups(output, expected_output));
}