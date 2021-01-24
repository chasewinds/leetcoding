#include <iostream>
#include <vector>
#incldue <unordered_map>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {};
    }
    unordered_map<int, int> n2f;
    for (int i = 0; i < nums.size(); i++) {
      n2f[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); i++) {
      int rest = target - nums[i];
      if (auto it = n2f.find(rest); it != n2f.end() && it->second != i) {
        return i <= it->second ? vector<int>{i, it->second} : vector<int>{it->second, i};
      }
    }
    return {};
  }
};
