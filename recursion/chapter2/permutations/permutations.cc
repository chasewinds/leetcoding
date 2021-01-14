#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
// back track
class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {

    if (nums.empty()) {
      return vector<vector<int>>();
    }

    vector<vector<int>> res;
    vector<int> cur;
    helper(res, cur, nums);

    return res;
  }

  void helper(vector<vector<int>>& res, vector<int>& cur, vector<int>& remain) {
    if (remain.empty()) {
      res.push_back(cur);
      return;
    }

    for (int i = 0; i < remain.size(); i++) {
      cur.push_back(remain[i]);
      vector<int> next = newVectorWithout(i, remain);
      helper(res, cur, next);
      cur.pop_back();
    }
  }

  vector<int> newVectorWithout(int idx, vector<int> source) {

    vector<int> ret;
    for (int i = 0; i < source.size(); i++) {
      if (i == idx) {
        continue;
      }
      ret.push_back(source[i]);
    }

    return ret;
  }
};
*/

class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.empty()) {
      return vector<vector<int>>();
    }

    queue<vector<int>> bfsQ;
    for (int i = 0; i < nums.size(); i++) {
      bfsQ.push(vector<int>{i});
    }

    vector<vector<int>> res;

    while (!bfsQ.empty()) {
      vector<int> topL = bfsQ.front();
      bfsQ.pop();
      vector<int> nextL;
      for (int i = 0; i < nums.size(); i++) {
        bool in = false;
        for (int j : topL) {
          if (i == j) {
            in = true;
            break;
          }
        }
        if (!in) {
          nextL.push_back(i);
        }
      }

      if (nextL.size() == 0) {
        vector<int> actual;
        for (int i : topL) {
          actual.push_back(nums[i]);
        }
        res.push_back(actual);
        continue;
      }

      for (int x : nextL) {
        topL.push_back(x);
        bfsQ.push(topL);
        topL.pop_back();
      }
    }

    return res;
  }
};


int main() {
  auto s = new Solution;
  vector<int> input = vector<int>{1, 2, 3};
  vector<vector<int>> ret = s->permute(input);
  for (auto list : ret) {
    for (auto x : list) {
      cout << x;
    }
    cout << endl;
  }
  return 0;
}