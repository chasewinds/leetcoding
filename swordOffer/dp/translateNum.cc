#include <iostream>
#include <vector>

using namespace std;
class Solution {
 public:
  int translateNum(int num) {
    if (num < 10) {
      return 1;
    }

    int res = 1;
    int prev = 26;
    int q = 1;
    int s = 1;
    while (num > 0) {
      int m = num % 10;
      //   cout << "x: "<< m * 10 + prev << endl;
      if (int x = m * 10 + prev; x <= 25 && m != 0 && x != 0) {
        res = q + s;
      } else {
        res = q;
      }
      prev = m;
      s = q;
      q = res;
      num /= 10;
    }

    return res;
  }
};