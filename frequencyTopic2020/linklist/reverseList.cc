#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/*
// by loop
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *prev = nullptr;
    ListNode *node = head;
    while (node->next != nullptr) {
      ListNode *next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }
    node->next = prev;
    return node;
  }
};
*/

// by recursive
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    return reverse(nullptr, head);
  }

  ListNode* reverse(ListNode *prev, ListNode *head) {
    if (head->next == nullptr) {
      head->next = prev;
      return head;
    }
    ListNode *next = head->next;
    head->next = prev;
    return reverse(head, next);
  }
};