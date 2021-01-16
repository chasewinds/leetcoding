#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numWays(int n ) {

    if (n < 2) {
      return 1;
    }

    int n1 = 1;
    int n2 = 1;
    int res = 0;

    for (int i = 2; i <= n; i++) {
      res = (n1 + n2) % 1000000007;
      n1 = n2;
      n2 = res;
    }

    return res;
  }
};