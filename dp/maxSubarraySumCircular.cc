#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& A) {
    if (A.empty()) {
      return 0;
    }
    if (A.size() == 1) {
      return A[0];
    }

    vector<int> B = vector<int>(2 * A.size());
    B[0] = A[0];
    for (int i = 1; i < B.size(); i++) {
      B[i] = A[i % A.size()] + B[i - 1];
    }

    // search max(B[j] - B[i]) when (j - i) < A.size()
    deque<int> q;
    q.push_back(0);
    int ans = A[0];

    for (int i = 1; i <= B.size(); i++) {
      while (B[q.front()] + A.size() < i) {
        q.pop_front();
      }
      ans = max(ans, B[i] - B[q.front()]);

      while (!q.empty() && B[q.back()] >= B[i]) {
        q.pop_back();
      }
      q.push_back(i);
    }

    return ans;
  }
};

int main() {
  auto s = new Solution;
  vector<int> input = vector<int>{3, -1, 2, -1};
  cout << s->maxSubarraySumCircular(input);
  return 0;
}