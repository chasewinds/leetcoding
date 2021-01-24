#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    ListNode *prev = new ListNode(0);
    ListNode *res = prev;
    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val >= l2->val) {
        prev->next = l2;
        l2 = l2->next;
      } else {
        prev->next = l1;
        l1 = l1->next;
      }
      prev = prev->next;
    }
    if (l1 != nullptr) {
      prev->next = l1;
    }
    if (l2 != nullptr) {
      prev->next = l2;
    }
    return res->next;
  }
};
