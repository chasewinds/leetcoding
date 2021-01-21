#include <iostream>
#include <vector>

using namespace std;

/*
// burst force by merge arr
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
*/

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

    if (nums2.size() > nums1.size()) {
      return findMedianSortedArrays(nums2, nums1);
    }
    int m = nums1.size();
    int n = nums2.size();

    int nLeftPart = (m + n + 1) / 2;
    int left = 0;
    int right = m;
    int m1 = 0;
    int m2 = 0;

    while (left <= right) {
      int mid = (left + right) / 2;
      int nid = nLeftPart - mid;

      int leftM = (mid == 0 ? INT_MIN : nums1[mid - 1]);
      int rightM = (mid == m ? INT_MAX : nums1[mid]);
      int leftN = (nid == 0 ? INT_MIN : nums2[nid - 1]);
      int rightN = (nid == n ? INT_MAX : nums2[nid]);
      if (leftM <= rightN) {
        left = mid + 1;
        m1 = max(leftM, leftN);
        m2 = min(rightM, rightN);
      } else {
        right = mid - 1;
      }
    }

    if ((m + n) % 2 == 1) {
      return m1;
    }
    return (m1 + m2) / 2.0;
  }
};
