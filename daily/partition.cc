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
  ListNode* partition(ListNode* head, int x) {

    ListNode *wa = new ListNode(0);
    ListNode *pva = wa;
    ListNode *wb = new ListNode(0);
    ListNode *pvb = wb;

    for (ListNode* cur = head; cur != nullptr; cur = cur->next) {

      if (cur->val < x) {
        wa->next = cur;
        wa = wa->next;
      } else {
        wb->next = cur;
        wb = wb->next;
      }

    }

    wb->next = nullptr;
    wa->next = pvb->next;
    return pva->next;
  }
};

int main() {
  auto s = new Solution;
  ListNode *head = new ListNode(1, new ListNode(4, new ListNode(3, new ListNode(2, new ListNode(5, new ListNode(2))))));
  ListNode *res = s->partition(head, 3);
  for (auto cur = res; cur != nullptr; cur = cur->next) {
    cout << cur->val << endl;
  }
}