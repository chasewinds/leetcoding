#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    int count = 0;
    int cur = nums[0] - 1;
    for (int x : nums) {
      if (count == 0) {
        cur = x;
      }
      if (cur == x) {
        count++;
      } else {
        count--;
      }

    }

    return cur;
  }
};

int main() {}