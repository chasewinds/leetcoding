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
  ListNode* reverseList(ListNode *head) {

    if (head == nullptr) {
      return nullptr;
    }

    ListNode *prev = nullptr;
    ListNode *cur = head;
    while (cur != nullptr) {
      ListNode *next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }

    return prev;
  }
};

int main() {
  cout << "main" << endl;
  auto s = new Solution;
  ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, nullptr)))));
  ListNode* nhead = s->reverseList(head);
  cout << nhead;
}