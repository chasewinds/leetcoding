#include <iostream>
#include <stack>

using namespace std;

/*
// double stack
class MinStack {
 public:
  stack<int> stdstk;
  stack<int> minstk;
  MinStack() {
    stdstk = {};
    minstk = {};
  }

  void push(int x) {
    stdstk.push(x);
    if (minstk.empty() || x <= getMin()) {
      minstk.push(x);
    }
  }

  void pop() {
    int top = stdstk.top();
    stdstk.pop();
    if (top == minstk.top()) {
      minstk.pop();
    }
  }

  int top() {
    return stdstk.top();
  }

  int getMin() {
    return minstk.top();
  }
};
*/

struct LinkList {
  int val;
  int cmin;
  LinkList *next;
  LinkList(int x, int y) : val(x), cmin(y), next(nullptr) {}
};

class MinStack {
 public:
  LinkList* head;
  MinStack() {
    head = nullptr;
  }

  void push(int x) {
    if (head == nullptr) {
      head = new LinkList(x, x);
    } else {
      auto *cur = new LinkList(x, min(x, head->cmin));
      cur->next = head;
      head = cur;
    }
  }

  void pop(int x) {
    if (head != nullptr) {
      head = head->next;
    }
  }

  int top() {
    if (head != nullptr) {
      return head->val;
    }
    return -1;
  }

  int getMin() {
    if (head != nullptr) {
      return head->cmin;
    }
    return -1;
  }
};