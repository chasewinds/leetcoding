#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.empty()) {
      return 0;
    }

    int left = 0;
    int right = nums.size() - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (target < nums[mid]) {
        right = mid - 1;
      } else if (target > nums[mid]) {
        left = mid + 1;
      } else {
        int p1 = mid;
        int p2 = mid;
        while (nums[p1 + 1] == nums[mid]) {
          p1++;
        }
        while (nums[p2 - 1] == nums[mid]) {
          p2--;
        }
        return p1 - p2 + 1;
      }
    }

    return 0;
  }
};

int main() {

}