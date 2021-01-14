#include <iostream>

using namespace std;

struct CycleLinkList {
  int val;
  CycleLinkList *next;
  CycleLinkList(int x) : val(x), next(nullptr) {}
};

// burst force, can only pass 26 /36 cases
class Solution {
 public:
  int lastRemaining(int n, int m) {

    if (n == 0 || n == 1) {
      return n;
    }

    CycleLinkList *head = new CycleLinkList(0);
    CycleLinkList *p = head;
    for (int i = 1; i < n; i++) {
      CycleLinkList *next = new CycleLinkList(i);
      p->next = next;
      p = p->next;
    }

    p->next = head;

    CycleLinkList *prev = p;
    while (head->next != head) {
      for (int i = 0; i < m; i++) {
        prev = head;
        head = head->next;
      }
      CycleLinkList *next = head->next;
      prev->next = next;
      head = next;
    }

    return head->val;
  }
};

int main() {

}