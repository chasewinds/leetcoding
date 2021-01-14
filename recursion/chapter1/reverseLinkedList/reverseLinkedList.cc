#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  //    ListNode* reverseList(ListNode* head) {
  //        if (head == nullptr) {
  //            return nullptr;
  //        }
  //        ListNode *prev = nullptr;
  //        for (ListNode* node = head; node != nullptr; ) {
  //            ListNode *next = node->next;
  //            node->next = prev;
  //            prev = node;
  //            node = next;
  //        }
  //        return prev;
  //    }
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode* p = reverseList(head->next);
    cout << "head now" << head->val << endl;
    head->next->next = head;
    head->next = nullptr;
    return p;
  }
};

int main() {
  auto s = new Solution;
  //    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new
  //    ListNode(4, new ListNode(5, nullptr)))));
  ListNode* twoNode = new ListNode(1, new ListNode(2, nullptr));
  ListNode* newHead = s->reverseList(twoNode);
  for (ListNode* x = newHead; x != nullptr; x = x->next) {
    cout << x->val << endl;
  }

  return 0;
}