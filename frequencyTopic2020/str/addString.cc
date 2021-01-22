#include <iostream>
#include <string>

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    if (num1.empty()) {
      return num2;
    }
    if (num2.empty()) {
      return num1;
    }
    int p1 = num1.size() - 1;
    int p2 = num2.size() - 1;
    int up = 0;
    string res = "";
    while (p1 >= 0 || p2 >= 0 || up != 0) {
      int sum = up;
      if (p1 <= num1.size() - 1) {
        sum += char2int(num1[p1]);
      }
      if (p2 <= num2.size() - 1) {
        sum += char2int(num2[p2]);
      }
//      cout << "sum: " << sum << endl;
      if (sum >= 10) {
        up = sum / 10;
        sum = sum % 10;
      } else {
        up = 0;
      }
      res.push_back('0' + sum);
      p1--;
      p2--;
    }
    reverse(res.begin(), res.end());
    return res;
  }
  int char2int(char c) {
    return c - '0';
  }
};

int main() {
  auto s = new Solution;
  cout << s->addStrings("98", "9");
  return 0;
}