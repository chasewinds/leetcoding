#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> printNumbers(int n) {
    vector<int> res;
    res.reserve(n * 10);
    for (int i = 1; i < n * 10; i++) {
      res.push_back(i);
    }
    return res;
  }
};