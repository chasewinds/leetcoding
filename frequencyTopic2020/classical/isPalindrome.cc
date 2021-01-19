#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  bool isPalindrome(string s) {
    if (s.empty()) {
      return true;
    }

    int i = 0;
    int j = s.size() - 1;
    while (i <= j) {
      while (i < s.size() && !isalnum(s[i])) {
        i++;
      }
      while (j >= 0 && !isalnum(s[j])) {
        j--;
      }
      if (i < s.size() && j >= 0) {
        if (!seam(s[i], s[j])) {
          return false;
        }
      }

      i++;
      j--;
    }
    return true;
  }
  // this func work out fine in my c11 compiler, but failed in leetcode compiler
  // so use isalnum instead.
  bool valid(char x) {
    return x != ' ' && ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
  }
  bool seam(char x, char y) {
    if (x == y) {
      return true;
    }
    int partition = 'a' - 'A';
    if (abs(x - y) == partition) {
      return true;
    }
    return false;
  }
};

int main() {
  auto s = new Solution;
//    cout << s->isPalindrome("A man, a plan, a canal: Panama") << endl;
//  cout << s->isPalindrome(" ") << endl;
  cout << s->isPalindrome("OP") << endl;
}