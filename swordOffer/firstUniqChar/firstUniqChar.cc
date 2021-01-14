#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
 public:
  char firstUniqChar(string s) {

    if (s.empty()) {
      return ' ';
    }

    vector<char> memo = vector<char>(26);
    for (char c: s) {
      memo[c - 'a'] = true;
    }

    for (char c: s) {
      if (!memo[c - 'a']) {
        return c;
      }
    }

    return ' ';
  }
};

int main() {
  auto s = new Solution;
  cout << s->firstUniqChar("leetcode");
  cout << "x";
  return 0;
}