#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* getKthFromEnd(ListNode *head, int k) {

    if (head == nullptr) {
      return nullptr;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    for (int i = 0; i < k; i++) {
      fast = fast->next;
      if (fast == nullptr) {
        return slow;
      }
    }

    while (slow != nullptr && fast != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    return slow;
  }
};