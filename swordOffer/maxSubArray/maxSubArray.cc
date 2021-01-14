#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    vector<int> dp;
    dp.reserve(nums.size());
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i - 1 < 0) {
        dp[i] = nums[i];
        res = dp[i];
        continue;
      }
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      if (dp[i] > res) {
        res = dp[i];
      }
    }

    return res;
  }
};

int main() {
  auto s = new Solution;
  vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  cout << s->maxSubArray(input) << endl;
}