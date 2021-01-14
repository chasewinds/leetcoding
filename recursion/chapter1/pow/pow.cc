#include <iostream>

using namespace std;

class Solution {
 public:
  double myPowRec(double x, double cur, int n) {
    cout << cur << " " << n << endl;
    if (n == 1) {
      return cur;
    }
    if (n > 0) {
      if (n == 3 || n == 5 || n == 7) {
        n--;
        cur *= x;
      } else {
        n /= 2;
        cur = cur * cur;
      }
    } else {
      if (n == -3 || n == -5 || n == -7) {
        n++;
        cur /= x;
      } else {
        n /= 2;
        cur *= 1/x * 1/x;
      }
    }
    return myPowRec(x, cur, n);
  }

  double myPow(double x, int n) {
    if (x == 0) {
      return 0;
    }
    return myPowRec(x, x, n);
  }
};




int main() {
  auto s = new Solution;
  cout << s->myPow(2.00000, 10) << endl;
  return 0;
}