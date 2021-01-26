#include <iostream>
#include <vector>

using namespace std;

// quick select based on quick sort
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    return diveAndQuarter(nums, 0, nums.size() - 1, nums.size() - k);
  }

  int diveAndQuarter(vector<int>& nums, int i, int j, int k) {
    // rand partition
    int ridx = (rand() % (j - i + 1)) + i;
    swap(nums[ridx], nums[j]);
    // part sort
    int pidx = partition(nums, i, j);
    // check idx with k
    if (pidx == k) {
      return nums[k];
    }
    // recursive search left or right
    if (pidx > k) {
      return diveAndQuarter(nums, i, pidx - 1, k);
    }
    return diveAndQuarter(nums, pidx + 1, j, k);
  }

  /*
  int partition(vector<int>& nums, int l, int r) {
    int pvalue = nums[r];
    for (int i = l; i < r; i++) {
      if (nums[i] <= pvalue) { // k largest, so sort reversed
        swap(nums[i], nums[r]);
        r = i;
      }
    }
    return p;
  }
  */

  // also ok
  int partition(vector<int>& a, int l, int r) {
    int pivotValue = a[r];
    int storeIdx = l;
    for (int i = l; i < r; i++) {
      if (a[i] <= pivotValue) {
        swap(a[i], a[storeIdx]);
        storeIdx++;
      }
    }
    swap(a[storeIdx], a[r]);
    return storeIdx;
  }


  /*
   * copy from ans
  inline int partition(vector<int>& a, int l, int r) {
    int x = a[r], i = l - 1;
    for (int j = l; j < r; ++j) {
      if (a[j] <= x) {
        swap(a[++i], a[j]);
      }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
  }
   */
};

/*
//
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    if (nums.empty()) {
      return 0;
    }
    diveAndQuarter(nums, 0, nums.size() - 1);
    // for (auto x: nums) {
    //   cout << x << " ";
    // }
    return nums[nums.size() - k];
  }

  void diveAndQuarter(vector<int>& nums, int i, int j) {
    if (i == j) {
      return;
    }
    if (i + 1 == j) {
      if (nums[i] > nums[j]) {
        swap(nums[i], nums[j]);
      }
      return;
    }
    int mid = (i + j) / 2;
    diveAndQuarter(nums, i, mid);
    diveAndQuarter(nums, mid + 1, j);
    merge(nums, i, mid, j);
  }

  void merge(vector<int>& nums, int i, int mid, int j) {
    vector<int> temp;
    int p1 = i;
    int p2 = mid + 1;
    while (p1 <= mid && p2 <= j) {
      if (nums[p1] <= nums[p2]) {
        temp.push_back(nums[p1]);
        p1++;
      } else {
        temp.push_back(nums[p2]);
        p2++;
      }
    }
    while (p1 <= mid) {
      temp.push_back(nums[p1]);
      p1++;
    }
    while (p2 <= j) {
      temp.push_back(nums[p2]);
      p2++;
    }

    for (int x = 0; x < temp.size(); x++) {
      nums[x + i] = temp[x];
    }
  }
};
*/
