#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Solution {
 public:

  vector<string> generateParenthesis(int n) {
    queue<string>
  }


//  vector<string> generateParenthesis(int n) {
//    vector<string> res;
//    dfsSol(res, "", 0, 0, n * 2, n);
//    return res;
//  }
//
//  void dfsSol(vector<string>& res, string cur, int lpc, int rpc, int remain, int n) {
//
//    if (rpc > lpc) {
//      return;
//    }
//
//    if (remain == 0) {
//      if (lpc == n && rpc == n) {
//        res.push_back(cur);
//      }
//      return;
//    }
//
//    dfsSol(res, cur + "(", lpc + 1, rpc, remain - 1, n);
//    dfsSol(res, cur + ")", lpc, rpc + 1, remain - 1, n);
//  }
};

int main() {
  cout << "ma" << endl;
  auto s = new Solution;
  vector<string> res = s->generateParenthesis(3);
  for (auto x : res) {
    cout << x << endl;
  }

  return 0;
}