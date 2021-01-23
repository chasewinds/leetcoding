#include <iostream>
#include <vector>

using namespace std;

/*
// dp
class Solution {
 public:
  int trap(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    vector<int> leftMax = vector<int>(height.size());
    leftMax[0] = height[0];
    vector<int> rightMax = vector<int>(height.size());
    rightMax[0] = height[0];
    for (int i = 1; i < height.size(); i++) {
      leftMax[i] = max(height[i], leftMax[i - 1]);
    }
    for (int i = 1; i < height.size(); i++) {
      rightMax[i] = max(height[i], rightMax[i - 1]);
    }
    int res = 0;
    for (int i = 0; i < height.size(); i++) {
      res += min(rightMax[i], leftMax[i]) - height[i];
    }
    return res;
  }
};
*/

