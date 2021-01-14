#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
// hash
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {

    if (nums.empty()) {
      return vector<int>();
    }

    unordered_map<int, int> numToIdx;
    for (int i = 0; i < nums.size(); i++) {
      numToIdx.insert({nums[i], i});
    }

    for (int i = 0; i < nums.size(); i++) {
      int other = target - nums[i];
      if (auto it = numToIdx.find(other); it != numToIdx.end()) {
        return vector<int>{nums[i], nums[it->second]};
      }
    }

    return vector<int>();
  }
};
*/

// binary search
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {

    if (nums.empty()) {
      return vector<int>();
    }

    for (int i = 0; i < nums.size(); i++) {
      int other = target - nums[i];
      if (i + 1 < nums.size()) {
        int left = i + 1;
        int right = nums.size() - 1;
        while (left <= right) {
          int mid = (left + right) / 2;
          if (nums[mid] < other) {
            left = mid + 1;
          } else if (nums[mid] > other){
            right = mid - 1;
          } else {
            return vector<int>{nums[i], nums[mid]};
          }
        }
      }
    }

    return vector<int>();
  }
};