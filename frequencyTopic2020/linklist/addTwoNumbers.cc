#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    int up = 0;
    ListNode *prev = new ListNode(0);
    ListNode *before = prev;
    while (l1 != nullptr || l2 != nullptr || up != 0) {
      int sum = up;
      if (l1 != nullptr) {
        sum += l1->val;
      }
      if (l2 != nullptr) {
        sum += l2->val;
      }
      if (sum >= 10) {
        up = sum / 10;
        sum = sum % 10;
      } else {
        up = 0;
      }
      ListNode *node = new ListNode(sum);
      prev->next = node;
      prev = node;
      if (l1 != nullptr){
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }
    return before->next;
  }
};