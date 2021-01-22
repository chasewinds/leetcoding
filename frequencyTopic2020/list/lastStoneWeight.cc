#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
// 贪心的每次用最大的两个撞是不ac的 [31,26,33,21,40]
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    if (stones.empty()) {
      return 0;
    }
    priority_queue<int> q;
    for (int i = 0; i < stones.size(); i++) {
      q.push(stones[i]);
    }
    while (!q.empty()) {
      if (q.size() == 1) {
        return q.top();
      }
      int top1 = q.top();
      q.pop();
      int top2 = q.top();
      q.pop();
      int boom = top1 - top2;
      if (boom != 0) {
        q.push(boom);
      }
    }
    return 0;
  }
};
*/

// 背包, jump!
class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {

  }
};