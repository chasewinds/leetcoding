#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return vector<int>{-1, -1};
    }
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        int up = mid;
        while (up < nums.size() && nums[up] == nums[mid]) {
          up++;
        }
        int down = mid;
        while (down >= 0 && nums[down] == nums[mid]) {
          down--;
        }
        return vector<int>{down + 1, up - 1};
      }
    }
    return vector<int>{-1, -1};
  }
};

