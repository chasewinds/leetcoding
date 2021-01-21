#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    if (nums.size() < 3) {
      return vector<vector<int>>{};
    }
    sort(nums.begin(), nums.end());
    unordered_map<int, int> n2f;
    for (int i = 0; i < nums.size(); i++) {
      n2f[nums[i]] = i;
    }
    vector<vector<int>> memo;
    for (int i = 0; i < nums.size(); i++) {
      if (i != 0) {
        if(nums[i] == nums[i - 1]) {
          continue;
        }
      }
      for (int j = i + 1; j < nums.size(); j++) {
        if (j != i + 1 && nums[j] == nums[j - 1]) {
          continue;
        }
        int target = 0 - (nums[i] + nums[j]);
        if (auto it = n2f.find(target); it != n2f.end() && it->second > j) {
          vector<int> temp = vector<int>{nums[i], nums[j], nums[it->second]};
          sort(temp.begin(), temp.end());
          memo.push_back(temp);
        }
      }
    }
    return memo;
  }
};