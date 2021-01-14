#include <iostream>
#include <vector>

using namespace std;

/*
// search from bi-direction
class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    if (nums.empty()) {
      return vector<int>();
    }

    int len = nums.size() - 1;
    int left = 0;
    int right = len;
    while (left < right) {
      while (left < len && nums[left] % 2 != 0) {
        left++;
      }
      while (right > 0 && nums[right] % 2 == 0) {
        right--;
      }
      if (left < right) {
        swap(nums[left], nums[right]);
      }
    }

    return nums;
  }
};
*/

class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    if (nums.empty()) {
      return vector<int>();
    }

    int slow = 0;
    int fast = slow;

    while (fast < nums.size()) {
      if (nums[slow] % 2 != 0) {
        slow++;
      }
      if (fast < slow) {
        fast = slow;
      }
      while (fast < nums.size() && nums[fast] % 2 == 0) {
        fast++;
      }
      if (fast < nums.size()) {
        swap(nums[slow], nums[fast]);
      }
    }

    return nums;
  }
};

int main() {
  auto s = new Solution;
  vector<int> input = {1, 2, 3, 4};
  vector<int> res = s->exchange(input);
  for (int x : res) {
    cout << x;
  }
}