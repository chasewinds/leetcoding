#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {

    vector<int> b = vector<int>(a.size(), 1);
    for (int i = 1; i < a.size(); i++) {
      b[i] = b[i - 1] * a[i - 1];
    }

    int tmp = 1;
    for (int i = a.size() - 1; i > 0; i--) {
      tmp *= a[i];
      b[i - 1] *= tmp;
    }

    return b;
  }
};

int main() {
//  vector<int> input = vector<int>{1, 2, 3, 4, 5};
  vector<int> input = vector<int>{23};
  auto s = new Solution;
  vector<int> res = s->constructArr(input);
  for (auto x: res) {
    cout << x << " ";
  }
}