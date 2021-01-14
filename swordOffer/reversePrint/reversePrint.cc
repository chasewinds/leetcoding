#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};

class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {

    if (head == nullptr) {
      return vector<int>();
    }

    stack<ListNode*> stk;
    vector<int> res;
    for (ListNode *cur = head; cur != nullptr; cur = cur->next) {
      stk.push(cur);
    }

    while (!stk.empty()) {
      res.push_back(stk.top()->val);
      stk.pop();
    }

    return res;
  }
};