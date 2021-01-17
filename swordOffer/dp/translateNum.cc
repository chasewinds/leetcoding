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
    int prev = -1;
    while (num >= 10) {
      int m = num % 10;
      if (m * 10 + prev <= 25) {
        res = res + 1;
      }
      prev = m;
      num /= 10;
    }

    return res;
  }
};