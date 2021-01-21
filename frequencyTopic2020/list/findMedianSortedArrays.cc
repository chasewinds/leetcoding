#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();
    if (m + n == 0) {
      return 0;
    }
    vector<int> merge = vector<int>(m + n, 0);
    int p = 0;
    int i = 0;
    int j = 0;
    while (i < m && j < n) {
      if (nums1[i] <= nums2[j]) {
        merge[p] = nums1[i];
        i++;
      } else {
        merge[p] = nums2[j];
        j++;
      }
      p++;
    }
    if (i < m) {
      while (i < m) {
        merge[p] = nums1[i];
        i++;
        p++;
      }
    } else if (j < n) {
      while (j < n) {
        merge[p] = nums2[j];
        j++;
        p++;
      }
    }
    if ((m + n) % 2 == 1) {
      return merge[(m + n) / 2];
    }
    return (merge[(m + n) / 2] + merge[(m + n) / 2 + 1]) / 2.0;
  }
};
