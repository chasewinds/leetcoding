#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
// hash, runtime 5.01% / memo 5.02%, bad way
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty()) {
      return 0;
    }
    int p1 = 0;
    unordered_set<char> memo;
    int maxlen = 0;
    while (p1 < s.size()) {
      int p2 = p1 + 1;
      memo.clear();
      memo.insert(s[p1] - 'a');
      while (p2 < s.size() && memo.count(s[p2] - 'a') == 0) {
        memo.insert(s[p2] - 'a');
        p2++;
      }

      maxlen = max(maxlen, p2 - p1);
      p1++;
    }
    return maxlen;
  }
};
*/

// slide window
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    if (s.empty() || s.size() == 1) {
      return s.size();
    }
    int left = 0;
    int right = left + 1;
    unordered_set<char> memo;
    int res = 0;
    while (right < s.size()) {
      memo.insert(s[left]);
      while (right < s.size() && memo.count(s[right]) == 0) {
        memo.insert(s[right]);
        right++;
      }
      res = max(res, right - left);
      while (left < s.size() && left < right && !memo.empty() &&
             memo.count(s[right]) != 0) {
        memo.erase(s[left]);
        left++;
      }
      if (left == right) {
        right++;
      }
    }
    return res;
  }
};
