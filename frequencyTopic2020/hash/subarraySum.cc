#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) {
      return 0;
    }
    return subByIdx(nums, 0, k);
  }

  int subByIdx(vector<int>& nums, int i, int k) {
    int res = 0;
    while (i < nums.size()) {
      int j = i + 1;
      int sum = nums[i];
      while (j < nums.size() && sum + nums[j] != k) {
        j++;
        sum += nums[j];
      }
      if (sum == k) {
        if (j < nums.size() - 1) {
          res += 1 + subByIdx(nums, j, 0);
        }
        res++;
      }
      i++;
    }
    return res;
  }
};
