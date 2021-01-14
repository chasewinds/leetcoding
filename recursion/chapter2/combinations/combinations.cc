#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> combine(int n, int k) {
    if (k == 0) {
      return vector<vector<int>>();
    }
    vector<vector<int>> res;
    backTrackAllCombin(res, vector<int>{}, n, k);
    return res;
  }

  void backTrackAllCombin(vector<vector<int>>& res, vector<int> cur, int n, int k) {
    if (k == 0) {
      res.push_back(cur);
      cur.clear();
      return;
    }

    int startIdx = 1;
    if (cur.size() != 0) {
      startIdx = cur.back() + 1;
    }
//    cout << "start idx: " << startIdx << endl;
    for (int i = startIdx; i <= n; i++) {
      cur.push_back(i);
      backTrackAllCombin(res, cur, n, k - 1);
      cur.pop_back();
    }
  }
};

int main() {
  auto s = new Solution;
  auto res = s->combine(2, 2);
  for (auto row: res) {
    for (int x: row) {
      cout << x;
    }
    cout << endl;
  }
  return 0;
}