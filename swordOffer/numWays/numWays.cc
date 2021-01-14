#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int numWays(int n) {

    if (n == 0 || n == 1) {
      return 1;
    }

    vector<int> dp = vector<int>(n);
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++) {
      dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }

    return dp.back();
  }
};

int main() {
  auto s = new Solution;
  cout << s->numWays(2);
}