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
  ListNode* swapPairs(ListNode* head) {
    if (head == nullptr) {
      return nullptr;
    }

    ListNode* prev = new ListNode(0, head);
    swapAndGoNext(prev, head);
    return prev->next;
  }

  void swapAndGoNext(ListNode* prev, ListNode* node) {
    if (node == nullptr || node->next == nullptr) {
      return;
    }
    ListNode* next = node->next;

    // change node and next
    ListNode* nn = next->next;
    next->next = node;
    node->next = nn;
    prev->next = next;
    swapAndGoNext(node, nn);
  }
};

int main() {
  cout << "hi" << endl;
  ListNode* head =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  auto s = new Solution;
  ListNode* reversed = s->swapPairs(head);
  for (ListNode* head = reversed; head != nullptr; head = head->next) {
    cout << "node val: " << head->val << endl;
  }

  return 0;
}