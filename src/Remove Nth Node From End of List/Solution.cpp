#define CATCH_CONFIG_MAIN
#include "../catch.hpp"
#include <string>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* the_node_to_be_removed = nullptr;
    ListNode* the_node_before_to_be_removed = nullptr;
    ListNode* current = head;
    int distance = 0;
    while (current) {
      current = current->next;
      ++distance;
      if (distance == n) {
        the_node_to_be_removed = head;
      }
      if (distance == n + 1) {
        the_node_before_to_be_removed = head;
      }
      if (distance > n) {
        the_node_to_be_removed = the_node_to_be_removed->next;
      }
      if (distance > n + 1) {
        the_node_before_to_be_removed = the_node_before_to_be_removed->next;
      }
    }
    if (!the_node_to_be_removed) {
      return head;
    }
    if (the_node_to_be_removed && !the_node_before_to_be_removed) {
      assert(the_node_to_be_removed == head);
      return head->next;
    }
    assert(the_node_to_be_removed && the_node_before_to_be_removed);
    // warning: memory leaks
    the_node_before_to_be_removed->next = the_node_to_be_removed->next;
    return head;
  }
};

void DeleteList(ListNode* head) {
  if (head) {
    DeleteList(head->next);
    delete head;
  }
}

TEST_CASE("Test the solution for problem \"Remove Nth Node From End of List\"") {
  ListNode* list = new ListNode(1);
  list->next = new ListNode(2);
  list->next->next = new ListNode(3);
  list->next->next->next = new ListNode(4);
  list->next->next->next->next = new ListNode(5);

  Solution sln_instance;
  sln_instance.removeNthFromEnd(list, 2);
  CHECK(list->val == 1);
  CHECK(list->next->val == 2);
  CHECK(list->next->next->val == 3);
  CHECK(list->next->next->next->val == 5);
  CHECK(list->next->next->next->next == NULL);
  DeleteList(list);
}
