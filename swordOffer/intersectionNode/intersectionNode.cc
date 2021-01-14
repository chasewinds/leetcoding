#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
// hash set
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    unordered_map<ListNode*, bool> memo;
    for (ListNode *cur = headA; cur != nullptr; cur = cur->next) {
      memo.insert({cur, true});
    }

    for (ListNode *cur = headB; cur != nullptr; cur = cur->next) {
      if (auto it = memo.find(cur); it != memo.end()) {
        return it->first;
      }
    }

    return nullptr;
  }
};
*/

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode *walkA = headA;
    ListNode *walkB = headB;
    while (walkA != walkB) {
      if (walkA == nullptr) {
        walkA = headB;
      } else {
        headA = headA->next;
      }
      if (walkB == nullptr) {
        walkB = headA;
      } else {
        headB = headB->next;
      }
    }

    return walkA;
  }
};

int main() {
  auto s = new Solution;
  ListNode *inter = new ListNode(8, new ListNode(4, new ListNode(5)));
  ListNode *a = new ListNode(8, new ListNode(8, inter));
  ListNode *b = new ListNode(5, new ListNode(8, new ListNode(5, inter)));
  cout << s->getIntersectionNode(a, b)->val;
}