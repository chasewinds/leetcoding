#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*
// in place solution, can't hold multi space
class Solution {
 public:
  string reverseWords(string s) {
    if (s.empty()) {
      return "";
    }

    reverseByIdx(s, 0, s.size() - 1);
    if (s.size() > 1) {
      int left = 0;
      int right = left;
      while (left < s.size() && right + 1 < s.size() && right != s.size()) {
        while (right + 1 < s.size() && s[right + 1] != ' ') {
          right++;
        }
        reverseByIdx(s, left, right);
        left = right + 2;
        right = left;
      }
    }

    int left = 0;
    while (left < s.size() && s[left] == ' ') {
      left++;
    }
    s = s.substr(left);

    int right = s.size() - 1;
    while (right > -1 && s[right] == ' ') {
      right--;
    }
    s = s.substr(0, right + 1);

    return s;
  }

  void reverseByIdx(string& s, int x, int y) {
    while (x < y) {
      swap(s[x], s[y]);
      x++;
      y--;
    }
  }
};
*/

class Solution {
 public:
  string reverseWords(string s) {
    if (s.empty()) {
      return "";
    }

    stack<string> stk;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        continue;
      }

      int j = i;
      for (; j < s.size() - 1 && s[j + 1] != ' '; j++) {
      }
      string tmp;
      for (int k = i; k <= j; k++) {
        tmp.push_back(s[k]);
      }
      stk.push(tmp);
      i = j;
    }

    string res;
    while (!stk.empty()) {
      res += stk.top();
      stk.pop();
      if (!stk.empty()) {
        res += " ";
      }
    }

    return res;
  }
};

int main() {
  auto s = new Solution;
  cout << "\"" << s->reverseWords("  hello world!  ") << "\"";
  //  cout << "\"" << s->reverseWords("the sky is blue") << "\"";

  return 0;
}