#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int char2int(char c) { return int(c) - 49; }
  pair<char, char> n2cR(char offset) {
    int o = char2int(offset);
    switch (o) {
      case 1:
        return {'a', 'c'};
      case 2:
        return {'d', 'f'};
      case 3:
        return {'g', 'i'};
      case 4:
        return {'j', 'l'};
      case 5:
        return {'m', 'o'};
      case 6:
        return {'p', 's'};
      case 7:
        return {'t', 'v'};
      case 8:
        return {'w', 'z'};
      default:
        return {};
    }
  }

  vector<string> letterCombinations(string digits) {
    if (digits.empty()) {
      return vector<string>();
    }
    vector<string> res;
    backTrack(res, "", digits, 0);

    return res;
  }

  void backTrack(vector<string>& res, string cur, string digits, int idx) {
    if (idx == digits.size()) {
      res.push_back(cur);
      return;
    }

    pair<char, char> range = n2cR(digits[idx]);
    for (auto it = range.first; it != range.second + 1; it = char(it + 1)) {
      cur.push_back(it);
      backTrack(res, cur, digits, idx + 1);
      cur.pop_back();
    }
  }
};

int main() {
  auto s = new Solution;
  vector<string> res = s->letterCombinations("22");
  for (auto c : res) {
    cout << " : " << c;
  }
  return 0;
}