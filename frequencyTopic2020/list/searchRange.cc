#include <iostream>
#include <vector>

using namespace std;

/*
// 最后一圈边界有问题...
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
        while (nums[up] == nums[mid]) {
          up++;
        }
        int down = mid;
        while (nums[down] == nums[mid]) {
          down--;
        }
        return vector<int>{down + 1, up - 1};
      }
    }
    return vector<int>{-1, -1};
  }
};
*/

// ac, control sub matrix edge
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return {};
    }
    int left = 0;
    int right = matrix[0].size() - 1;
    int up = 0;
    int down = matrix.size() - 1;
    vector<int> res;
    while (left <= right && up <= down) {
      for (int c = left; c <= right; c++) {
        res.push_back(matrix[up][c]);
      }
      for (int r = up + 1; r <= down; r++) {
        res.push_back(matrix[r][right]);
      }
      if (left < right && up < down) {
        for (int c = right - 1; c > left; c--) {
          res.push_back(matrix[down][c]);
        }
        for (int r = down; r > up; r--) {
          res.push_back(matrix[r][left]);
        }
      }
      left++;
      right--;
      up++;
      down--;
    }
    return res;
  }
};
