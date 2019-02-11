#define CATCH_CONFIG_RUNNER
#include "../catch.hpp"
#include <cstddef>
#include <iostream>

using std::cin;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* new_head = NULL;

    
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
  for (size_t i = 0; i <= index; ++i) {
    node_ref = node_ref->next;
  }
  return node_ref->val;
}

TEST_CASE("Test the solution for problem \"Merge Two Sorted Lists\"") {
  ListNode* list_1 = new ListNode(1);
  list_1->next = new ListNode(2);
  list_1->next->next = new ListNode(4);
  ListNode* list_2 = new ListNode(1);
  list_2->next = new ListNode(3);
  list_2->next->next = new ListNode(4);
  Solution solution_instance;
  ListNode* merged_list = solution_instance.mergeTwoLists(list_1, list_2);
  REQUIRE(ValueAt(merged_list, 0) == 1);
  REQUIRE(ValueAt(merged_list, 1) == 1);
  REQUIRE(ValueAt(merged_list, 2) == 2);
  REQUIRE(ValueAt(merged_list, 3) == 3);
  REQUIRE(ValueAt(merged_list, 4) == 4);
  REQUIRE(ValueAt(merged_list, 5) == 4);
  DeleteList(merged_list);
}

int main(int argc, char* argv[]) {
  int result = Catch::Session().run(argc, argv);
  cin.get();
  return result;
}