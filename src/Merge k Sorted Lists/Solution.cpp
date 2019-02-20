/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <cstddef>
#include <vector>
#include <algorithm>

using std::vector;
using std::min_element;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

bool ListNodeComparator(ListNode* lhs, ListNode* rhs) {
  if (!lhs) {
    return true;
  }
  if (!rhs) {
    return false;
  }
  return lhs->val < rhs->val;
}

class Solution
{
public:
  ListNode* mergeKLists(vector<ListNode *> &lists)
  {
    ListNode* head = NULL;
    ListNode* current = NULL;
    while (lists.begin() != lists.end()) {
      vector<ListNode* >::iterator the_least_item = min_element(lists.begin(), lists.end(), ListNodeComparator);
      if (!(*the_least_item)) {
        lists.erase(the_least_item);
        continue;
      }
      if (!current) {
        assert(!head);
      }
      ListNode* previous = current;
      if (previous) {
        previous->next = *the_least_item;
      } else {
        head = *the_least_item;
      }
      current = *the_least_item;
      *the_least_item = (*the_least_item)->next;
    }
    return head;
  }
};

void DeleteList(ListNode* head) {
  ListNode* current = head;
  while (current) {
    ListNode* next_current = current->next;
    delete current;
    current = next_current;
  }
}

int ValueAt(ListNode* list, size_t index) {
  ListNode* node_ref = list;
  for (size_t i = 0; i < index; ++i) {
    node_ref = node_ref->next;
  }
  return node_ref->val;
}

TEST_CASE("Test the solution for problem \"Merge k Sorted Lists\"") {
  ListNode* list_1 = new ListNode(1);
  list_1->next = new ListNode(4);
  list_1->next->next = new ListNode(5);
  ListNode* list_2 = new ListNode(1);
  list_2->next = new ListNode(3);
  list_2->next->next = new ListNode(4);
  ListNode* list_3 = new ListNode(2);
  list_3->next = new ListNode(6);
  vector<ListNode*> lists_to_be_merged;

  lists_to_be_merged.push_back(list_1);
  lists_to_be_merged.push_back(list_2);
  lists_to_be_merged.push_back(list_3);
  Solution solution_instance;
  ListNode* merged_list = solution_instance.mergeKLists(lists_to_be_merged);

  REQUIRE(ValueAt(merged_list, 0) == 1);
  REQUIRE(ValueAt(merged_list, 1) == 1);
  REQUIRE(ValueAt(merged_list, 2) == 2);
  REQUIRE(ValueAt(merged_list, 3) == 3);
  REQUIRE(ValueAt(merged_list, 4) == 4);
  REQUIRE(ValueAt(merged_list, 5) == 4);
  REQUIRE(ValueAt(merged_list, 6) == 5);
  REQUIRE(ValueAt(merged_list, 7) == 6);
  DeleteList(merged_list);
}