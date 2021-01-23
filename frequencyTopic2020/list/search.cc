#include <iostream>
#include <vector>

using namespace std;

// finally ac...
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return -1;
    }
    if (nums.size() == 1) {
      return nums[0] == target ? 0 : -1;
    }
    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
//      cout << "mid: " << mid << " value: " << nums[mid] << endl;
      if (nums[mid] == target) {
        return mid;
      }
      if (nums[mid] >= nums[0]) {
        if (nums[mid] > target && target >= nums[0]) {
          right = mid - 1;
        } else {
          left = mid + 1;
        }
      } else if (nums[mid] <= nums.back()) {
        if (nums[mid] < target && target <= nums.back()) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        return -1;
      }
    }
//    if (left >= 0 && left < nums.size() && nums[left] == target) {
//      return left;
//    }
    return -1;
  }
};