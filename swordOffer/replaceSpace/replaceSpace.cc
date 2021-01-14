#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string replaceSpace(string s) {

    string res;
    for (char& c: s) {
      if (c == ' ') {
        res.push_back('%');
        res.push_back('2');
        res.push_back('0');
      } else {
        res.push_back(c);
      }
    }

    return res;
  }
};