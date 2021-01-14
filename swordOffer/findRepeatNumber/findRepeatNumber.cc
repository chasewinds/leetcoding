#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {

    if (nums.empty()) {
      return 0;
    }

    unordered_map<int, bool> memo;
    for (int & num : nums) {
      if (auto it = memo.find(num); it != memo.end()) {
        return num;
      }
      memo.insert({num, true});
    }

    return 0;
  }
};