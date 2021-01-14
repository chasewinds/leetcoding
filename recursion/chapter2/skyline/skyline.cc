#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

    vector<vector<int>> res;
    vector<vector<int>> stk;
    stk.push_back(vector<int>{0, 0, 0});
    for (int i = 0; i < buildings.size(); i++) {
      vector<int> build = buildings[i];

      if (build[0] > stk.back()[0] || (build[0] == stk.back()[0] && res.empty())) {
        res.push_back(vector<int>{build[0], build[1]});
        stk.push_back(build);
      } else if (build[0] == stk.back()[0]) {
        stk.back()[1] = build[1];
      } else {
        for (auto it = stk.rbegin(); it != stk.rend(); it++) {
          if (it[0])
        }
      }
    }
  }
};

int main() {
  cout << "m";
  return 0;
}