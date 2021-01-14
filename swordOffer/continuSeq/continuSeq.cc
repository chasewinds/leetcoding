#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

/*
// back track, TLE
class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {
    if (target == 0) {
      return vector<vector<int>>();
    }

    vector<vector<int>> res;
    vector<int> cur;
    backTrack(res, cur, 0, target);

    return res;
  }

  void backTrack(vector<vector<int>>& res, vector<int>& cur, int curSum,
                 int target) {
    if (curSum == target) {
      res.push_back(cur);
      return;
    }

    if (cur.empty()) {
      for (int i = 1; i < target / 2 + 1; i++) {
        cur.push_back(i);
        backTrack(res, cur, curSum + i, target);
        cur.pop_back();
      }
    } else {
      int top = cur.back() + 1;
      if (top < target) {
        cur.push_back(top);
        backTrack(res, cur, curSum + top, target);
        cur.pop_back();
      }
    }
  }
};
*/

// slide window
class Solution {
 public:
  vector<vector<int>> findContinuousSequence(int target) {

    if (target == 0 || target == 1 || target == 2) {
      return vector<vector<int>>();
    }

    vector<vector<int>> res;
    int left = 1;
    int right = 2;
    while (right < target && left < right) {
      int sum = (left + right) * (right - left + 1) / 2;
      if (sum > target) {
        left++;
      } else if (sum < target) {
        right++;
      } else {
        vector<int> oneRes;
        for (int i = left; i <= right; i++) {
          oneRes.push_back(i);
        }
        res.push_back(oneRes);
        left++;
      }
    }

    return res;
  }
};

int main() {
  auto s = new Solution;
  vector<vector<int>> res = s->findContinuousSequence(50252);
  for (auto row : res) {
    for (auto x : row) {
      cout << x << " ";
    }
    cout << endl;
  }
}