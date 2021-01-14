#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {

    if (nums.empty()) {
      return 0;
    }

    vector<int> minDP = vector<int>(nums.size());
    vector<int> maxDP = vector<int>(nums.size());
    maxDP[0] = nums[0];
    minDP[0] = nums[0];

    int res = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      minDP[i] = min(minDP[i - 1] * nums[i], min(nums[i], maxDP[i - 1] * nums[i]));
      maxDP[i] = max(maxDP[i - 1] * nums[i], max(nums[i], minDP[i - 1] * nums[i]));
      res = max(res, maxDP[i]);
    }

    return res;
  }
};

int main() {
  cout << "m" << endl;
  return 0;
}