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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }
    ListNode* prev = new ListNode;
    mergeRec(l1, l2, prev);
    return prev->next;
  }

  void mergeRec(ListNode* l1, ListNode* l2, ListNode* nnode) {
    if (l1 == nullptr && l2 == nullptr) {
      return;
    }
    int v1 = -101;
    int v2 = -101;
    if (l1 != nullptr) {
      v1 = l1->val;
    }
    if (l2 != nullptr) {
      v2 = l2->val;
    }
    cout << v1 << " " << v2 << " " << nnode->val << endl;
    if (v2 == -101 || (v1 <= v2 && v1 != -101)) {
      cout << "match 1"<< endl;
      ListNode* l1next = l1->next;
      l1->next = nullptr;
      nnode->next = l1;
      l1 = l1next;
    } else {
      cout << "match 2" << endl;
      ListNode* l2next = l2->next;
      l2->next = nullptr;
      nnode->next = l2;
      l2 = l2next;
    }
    nnode = nnode->next;
    mergeRec(l1, l2, nnode);
  }

//  ListNode* merge
};

int main() {

  auto s = new Solution;
//  ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
//  ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
  ListNode* l1 = new ListNode(2);
  ListNode* l2 = new ListNode(1);
  ListNode* merged = s->mergeTwoLists(l1, l2);
  for (ListNode* x = merged; x != nullptr; x = x->next) {
    cout << x->val << endl;
  }
  return 0;
}