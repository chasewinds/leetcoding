#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteNode(ListNode *head, int val) {

    if (head == nullptr) {
      return nullptr;
    }

    ListNode *prevh = new ListNode(0, head);
    ListNode *prev = prevh;
    for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
      if (cur->val == val) {
        prev->next = cur->next;
      }
      prev = cur;
    }

    return prevh->next;
  }
};