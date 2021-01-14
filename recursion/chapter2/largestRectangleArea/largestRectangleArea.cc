#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
// burst force
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    if (heights.size() == 0) {
      return 0;
    }
    if (heights.size() == 1) {
      return heights[0];
    }

    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
      int minHeight = INT_MAX;
      for (int j = i; j < heights.size(); j++) {
        int width = j - i + 1;
        if (minHeight > heights[j]) {
          minHeight = heights[j];
        }
        int area = width * minHeight;
        if (area > maxArea) {
          maxArea = area;
        }
      }
    }

    return maxArea;
  }
};
*/

class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    if (heights.empty()) {
      return 0;
    }
    if (heights.size() == 1) {
      return heights[0];
    }

    heights.insert(heights.begin(), 0);
    heights.push_back(0);
//    for (auto x : heights) {
//      cout << x;
//    }
//    cout << endl;

    stack<int> stk;
    stk.push(0);
    int maxArea = 0;
    for (int i = 1; i < heights.size(); i ++) {
      while (heights[stk.top()] > heights[i]) { // can pop
        int height = heights[stk.top()];
        stk.pop();
        int width = i - stk.top() - 1;
        int area = width * height;
        if (area > maxArea) {
          maxArea = area;
        }
      }
      stk.push(i);
    }

    return maxArea;
  }
};

int main() {
  auto s = new Solution;
  vector<int> input = vector<int>{2, 1, 5, 6, 2, 3};
  int res = s->largestRectangleArea(input);
  cout << res << endl;
  return 0;
}