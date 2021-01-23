#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty() || prices.size() == 1) {
      return 0;
    }

    int res = 0;
    int low = prices[0];
    for (int i = 1; i < prices.size();i++) {
      low = min(low, prices[i]);
      res = max(prices[i] - low, res);
    }
    return res;
  }
};
