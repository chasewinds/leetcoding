#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    if (s.empty()) {
      return true;
    }
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
      if (!stk.empty() && ((stk.top() == '(' && s[i] == ')') ||
                           (stk.top() == '{' && s[i] == '}') ||
                           (stk.top() == '[' && s[i] == ']'))) {
        stk.pop();
      } else {
        stk.push(s[i]);
      }
    }
    return stk.empty() ? true : false;
  }
};