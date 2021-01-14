#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
// burst force O(nk), can only pass 49 / 60 cases
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) {
      return vector<int>();
    }

    vector<int> res;
    int i = 0;
    int j = i + k - 1;
    int prevmax = nums[j];

    while (j < nums.size()) {
//      cout << "i: " << i << " j: " << j << endl;
      int max = nums[j];
      if (!(j < nums.size() && nums[j] > prevmax)) {
        for (int l = i; l <= j; l++) {
          if (nums[l] > max) {
            max = nums[l];
          }
        }
      }

      res.push_back(max);
      prevmax = max;
      i++;
      j++;
    }

    return res;
  }
};
*/

/*
// use heap, pass
class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    priority_queue<pair<int, int>> q;
    for (int i = 0; i < k; i++) {
      q.emplace(nums[i], i);
    }

    vector<int> res = {q.top().first};
    for (int i = k; i < nums.size(); i++) {
      q.emplace(nums[i], i);
      while (q.top().second <= i - k) {
        q.pop();
      }
      res.push_back(q.top().first);
    }

    return res;
  }
};
*/

// deque 
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

      if (nums.size() == 0 || k == 0) {
        return vector<int>();
      }

      vector<int> res;
      deque<int> q;
      for (int i = 1 - k, j = 0; j < nums.size(); i++, j++) {
        if (!q.empty() && i > 0 && q.front() == nums[i - 1]) {
          q.pop_front();
        }
        while (!q.empty() && q.back() < nums[j]) {
          q.pop_back();
        }
        q.push_back(nums[j]);
        if (!q.empty() && i >= 0) {
          res.push_back(q.front());
        }
      }
      return res;
    }
};

int main() {
  auto s = new Solution;
  vector<int> input {1, -1};
  for (auto x: s->maxSlidingWindow(input, 1)) {
    cout << x << endl;
  }
}