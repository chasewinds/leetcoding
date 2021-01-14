#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
// hash map
class Solution {
 public:
  bool isUnique(string astr) {

    if (astr.empty() || astr.size() == 1) {
      return true;
    }

    unordered_map<char, int> c2f;
    for (auto c: astr) {
      if (auto it = c2f.find(c); it != c2f.end()) {
        return false;
      } else {
        c2f.insert({c, 1});
      }
    }

    return true;
  }
};
*/

class Solution {
 public:
  bool isUnique(string astr) {
    if (astr.empty()) {
      return true;
    }

    int x = 0;
    for (int i = 0; i < astr.size(); i++) {
      auto binary = 1 << (astr[i] - 'a');
      if (x & binary) {
        return false;
      }
      x |= binary;
    }

    return true;
  }
};

int main() {
  auto s = new Solution;
  cout << s->isUnique("vrce");
  return 0;
}