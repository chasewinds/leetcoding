#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = head;
    for (int i = 1; i < n; i++) {
      if (fast == nullptr) {
        return nullptr;
      }
      fast = fast->next;
    }
    while (fast != nullptr && fast->next != nullptr) {
      prev = slow;
      slow = slow->next;
      fast = fast->next;
    }
    // cout << prev->val << " " << slow->val << endl;
    if (prev == slow) {
      return slow->next;
    }
    if (slow != nullptr) {
      prev->next = slow->next;
    } else {
      prev->next = nullptr;
    }
    return head;
  }
};
