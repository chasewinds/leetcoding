#include <iostream>
#include <map>

using namespace std;

class Solution {
 public:
//  int fib(int N) {
//
//    map<int, int> memo;
//    return fibWithMemo(N, memo);
//  }
//
//  int fibWithMemo(int N, map<int, int> memo) {
//
//    if (N < 2) {
//      return N;
//    }
//
//    auto it = memo.find(N);
//    if (it != memo.end()) {
//      return it->second;
//    }
//
//    int sum = fibWithMemo(N - 1, memo) + fibWithMemo(N - 2, memo);
//    memo.insert(pair<int, int>(N, sum));
//
//    return sum;
//  }
  int fib(int N) {
    if (N < 2) {
      return N;
    }
    return fib(N - 1) + fib(N - 2);
  }
};

int main() {
  auto s = new Solution;
  cout << s->fib(30) << endl;
  return 0;
}