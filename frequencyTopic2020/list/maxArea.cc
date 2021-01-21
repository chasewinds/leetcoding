#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    if (height.empty()) {
      return 0;
    }
    int left = 0;
    int right = height.size() - 1;
    int res = 0;
    while (left < right) {
      int cap = min(height[right], height[left]) * (right - left);
      res = max(res, cap);
      if (height[left] <= height[right]) {
        left++;
      } else {
        right--;
      }
    }
    return res;
  }
};