#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  string compressString(string s) {
    if (s.empty()) {
      return s;
    }

    string res;
    char prev = s.front();
    int count = 1;
    for (int i = 1; i < s.size(); i++) {
      char c = s[i];
      if (c == prev) {
        count++;
      } else {
        cout << prev << ('0' + count) << endl;
        res.push_back(prev + ('0' + count));
        count = 1;
      }
      prev = c;
    }

    return res;
  }
};