#include <deque>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

/*
class MaxQueue {
 public:
  stack<pair<int, int>> instk;
  stack<pair<int, int>> outstk;
  int outstkBottom;

  MaxQueue() {
    outstkBottom = 0;
  }

  int max_value() {

    if (!outstk.empty()) {
      return outstk.top().second;
    }
    if (!instk.empty()) {
      int curMax = instk.top().first;
      outstkBottom = instk.top().second;
      while (!instk.empty()) {
        pair<int, int> top = instk.top();
        curMax = max(top.first, curMax);
        instk.pop();
        outstk.push({top.first, curMax});
      }
      return outstk.top().second;
    }

    return -1;
  }

  void push_back(int value) {
    if (instk.empty()) {
      if (outstk.empty()) {
        instk.push({value, value});
        return;
      }
      instk.push({value, max(value, outstkBottom)});
    }
    instk.push({value, max(value, instk.top().second)});
  }

  int pop_front() {

    if (!outstk.empty()) {
      pair<int, int> top = outstk.top();
      outstk.pop();
      return top.first;
    }

    if (!instk.empty()) {
      int curMax = instk.top().first;
      while (!instk.empty()) {
        pair<int, int> top = instk.top();
        curMax = max(top.first, curMax);
        instk.pop();
        outstk.push({top.first, curMax});
      }
      auto top = outstk.top();
      outstk.pop();
      return top.first;
    }

    return -1;
  }
};
*/

class MaxQueue {
 public:
  deque<int> downQueue;
  queue<int> outQueue;
  MaxQueue() {}

  int max_value() {

    if (!downQueue.empty()) {
      return downQueue.front();
    }

    return -1;
  }

  void push_back(int value) {
    while(!downQueue.empty() && downQueue.back() < value) {
      downQueue.pop_back();
    }
    downQueue.push_back(value);
    outQueue.push(value);
  }

  int pop_front() {

   if (!outQueue.empty()) {
     int ans = outQueue.front();
     outQueue.pop();
     if (ans == downQueue.front()) {
       downQueue.pop_front();
     }
     return ans;
   }

   return -1;
  }
};

