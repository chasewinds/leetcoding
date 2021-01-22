#include <iostream>
#include <string>

using namespace std;

//
class Solution {
 public:
  bool validPalindrome(string s) {
    return tryx(s, true);
  }

  // 递归参数传idx可以更优雅
  bool tryx(string s, bool canTry) {
    if (s.empty()) {
      return true;
    }
    int head = 0;
    int tail = s.size() - 1;
    bool tolerance = true;
    while (head < tail ) {
      // cout << "s[head]: " <<s[head] << " s[tail] " << s[tail] << endl;
      if (s[head] == s[tail]) {
        head++;
        tail--;
        continue;
      }
      if (tolerance) {
        tolerance = false;
        head++;
      } else if (canTry){
        reverse(s.begin(), s.end());
        return tryx(s, false);
      } else {
        return false;
      }
    }
    return true;
  }
};
