#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string reverseLeftWords(string s, int n) {

    string tail;
    string head;
    for (int i = 0; i < s.size(); i++) {
      if (i < n) {
        head.push_back(s[i]);
      } else {
        tail.push_back(s[i]);
      }
    }

    for (char& c: head) {
      tail.push_back(c);
    }

    return tail;
  }
};

int main() {
  cout << "m" << endl;
  return 0;
}