#include <iostream>

using namespace std;

class Solution {
 public:
  int kthGrammar(int N, int K) {
    if (N == 1) {
      return 0;
    }
    if (N == 2) {
      return K - 1;
    }
    int bias = K % 2;
    int last = kthGrammar(N - 1, K / 2 + bias);
    switch (last) {
      case 1:
        if (bias == 0) {
          return 0;
        }
        return 1;
      case 0:
        if (bias == 0) {
          return 1;
        }
        return 0;
      default:
        cout << "go to unexcept case" << endl;
    }
    return 0;
  }
};

int main() {
  auto s = new Solution;
  cout << "res: " << s->kthGrammar(1, 1) << endl;
  cout << "res: " << s->kthGrammar(2, 1) << endl;
  cout << "res: " << s->kthGrammar(2, 2) << endl;
  cout << "res: " << s->kthGrammar(4, 5) << endl;
  cout << "res: " << s->kthGrammar(3, 2) << endl;

  return 0;
}