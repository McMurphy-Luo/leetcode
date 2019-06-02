#define CATCH_CONFIG_MAIN
#include "../catch.hpp"


struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* current_1 = l1;
    ListNode* current_2 = l2;
    ListNode* result = nullptr;
    ListNode* result_current = nullptr;
    bool carry = false;
    while (current_1 || current_2) {
      int val_1 = 0;
      int val_2 = 0;
      if (current_1) {
        val_1 = current_1->val;
      }
      if (current_2) {
        val_2 = current_2->val;
      }
      assert(val_1 >= 0 && val_1 <= 9);
      assert(val_2 >= 0 && val_2 <= 9);
      int sum = val_1 + val_2 + (carry ? 1 : 0);
      carry = sum >= 10;
      if (carry) {
        sum -= 10;
      }
      if (!result) {
        result = new ListNode(sum);
        result_current = result;
      }
      else {
        result_current->next = new ListNode(sum);
        result_current = result_current->next;
      }
      if (current_1) {
        current_1 = current_1->next;
      }
      if (current_2) {
        current_2 = current_2->next;
      }
    }
    if (carry) {
      result_current->next = new ListNode(1);
    }
    return result;
  }
};

void DeleteList(ListNode* head) {
  ListNode* current = head;
  ListNode* next = current->next;
  while (current) {
    next = current->next;
    delete current;
    current = next;
  }
}

TEST_CASE() {
  ListNode* list_1 = new ListNode(2);
  list_1->next = new ListNode(4);
  list_1->next->next = new ListNode(3);
  ListNode* list_2 = new ListNode(5);
  list_2->next = new ListNode(6);
  list_2->next->next = new ListNode(4);
  Solution solution_instance;
  ListNode* result = solution_instance.addTwoNumbers(list_1, list_2);
  REQUIRE(result);
  REQUIRE(result->val == 7);
  REQUIRE(result->next->val == 0);
  REQUIRE(result->next->next->val == 8);
  DeleteList(list_1);
  DeleteList(list_2);
  DeleteList(result);
}