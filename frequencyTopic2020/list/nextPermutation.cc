#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.empty()) {
      return;
    }
    int p1 = -1;
    for (int i = nums.size() - 2; i >= 0; i--) {
      if (nums[i + 1] > nums[i]) {
        p1 = i;
        break;
      }
    }
    if (p1 != -1) {
      int p2 = -1;
      for (int i = nums.size() - 1; i >= p1; i--) {
        if (nums[i] > nums[p1]) {
          p2 = i;
          break;
        }
      }
      swap(nums[p1], nums[p2]);
    }

    int left = p1 + 1;
    int right = nums.size() - 1;
    while (left < right) {
      swap(nums[left], nums[right]);
      left++;
      right--;
    }
    return;
  }
};
