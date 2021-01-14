#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void merge(vector<int>& A, int m, vector<int>& B, int n) {
    for (int i = 0; i < n; i++) {
      A[i + m] = B[i];
    }

    int right = m;
    while (right < m + n) {
      int left = 0;
      while (left < right) {
        if (A[left] > A[right]) {
          swap(A[left], A[right]);
        }
        left++;
      }
      right++;
    }
  }
};

int main() {
  auto s = new Solution;
  vector<int> a = {1, 2, 3, 0, 0, 0};
  vector<int> b = {2, 5, 6};
  s->merge(a, 3, b, 3);
}