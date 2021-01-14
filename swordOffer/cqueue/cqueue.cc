#include <iostream>
#include <stack>

using namespace std;

class CQueue {
 public:
  stack<int> instk;
  stack<int> outstk;
  CQueue() {
    instk = {};
    outstk = {};
  }

  void appendTail(int value) {
    instk.push(value);
  }

  int deleteHead() {
    if (instk.empty() && outstk.empty()) {
      return -1;
    }

    if (outstk.empty()) {
      while (!instk.empty()) {
        int top = instk.top();
        outstk.push(top);
        instk.pop();
      }
    }

    int res = outstk.top();
    outstk.pop();

    return res;
  }
};