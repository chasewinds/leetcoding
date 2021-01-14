#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
 public:
  // memo by vector, cause n step stairs only need n-len arr memo.
  int climbStairs(int n) {
    vector<int> memo = vector<int>(n + 1, -1);
    return climbWithTrickyMemo(n, memo);
  }

  int climbWithTrickyMemo(int n, vector<int>& memo) {
    if (n < 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    if (memo[n] != -1) {
      return memo[n];
    }
    int res = climbWithTrickyMemo(n - 1, memo) + climbWithTrickyMemo(n - 2, memo);
    memo[n] = res;
    return res;
  }

  // memo by map
  int climbStairsWithMap(int n) {
    map<int, int> memo = map<int, int>{};
    return climbWithMemo(n, memo);
  }

  int climbWithMemo(int n, map<int, int>& memo) {
    if (n < 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    auto it = memo.find(n);
    if (it != memo.end()) {
      return it->second;
    }

    int aprochs = climbWithMemo(n - 1, memo) + climbWithMemo(n - 2, memo);
    memo.insert(pair<int, int>(n, aprochs));
    return aprochs;
  }

  // pure search
  int climbStairsPure(int n) {
    if (n < 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
  }
};

int main() {
  auto s = new Solution;
  cout << s->climbStairs(44);
  return 0;
}