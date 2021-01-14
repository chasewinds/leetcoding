#include <iostream>
#include <vector>

using namespace std;

/*
// brace force
class Solution {
 public:
  int minArray(vector<int>& numbers) {

    if (numbers.empty()) {
      return 0;
    }

    int prev = numbers[0];
    for (int x : numbers) {
      if (x < prev) {
        return x;
      }
      prev = x;
    }

    return numbers.front();
  }
};
*/

class Solution {
 public:
  int minArray(vector<int>& numbers) {
    if (numbers.empty()) {
      return 0;
    }

    int left = 0;
    int right = numbers.size() - 1;
    int target = numbers.back();

    while (left < right) {
      int mid = (left + right) / 2;
      if (numbers[mid] > target) {
        left = mid + 1;
      } else if (numbers[mid] < target) {
        right = mid;
        target = numbers[right];
      } else {
        right--;
        target = numbers[right];
      }
    }

    return numbers[left];
  }
};

int main() {
  vector<int> input = {3, 4, 5, 1, 2};
  auto s = new Solution;
  cout << s->minArray(input);
  return 0;
}