#include <iostream>
#include <vector>

using namespace std;

// must sort... if use n2 sort will TLE in last case.
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return vector<vector<int>>();
    }

    // 原来 cpp会自动除了两个元素的列表的排序....所以下面这句话 = sort(intervals.begin(), intervals.end());
    sort(intervals.begin(), intervals.end(),
         [](const vector<int>& arr1, const vector<int>& arr2) {
           return (arr1[0] < arr2[0] ||
                   (arr1[0] == arr2[0] && arr1[1] < arr2[1]));
         });

    int i = 0;
    vector<bool> merged = vector<bool>(intervals.size(), false);
    while (i < intervals.size()) {
      if (merged[i]) {
        continue;
      }
      int j = i + 1;
      while (j < intervals.size()) {
        vector<int> interval = intervals[j];
        if (interval[0] <= intervals[i][1]) {
          // cout << "match" << endl;
          intervals[i][0] = min(intervals[i][0], interval[0]);
          intervals[i][1] = max(intervals[i][1], interval[1]);
          //   cout << intervals[i][0] << " " << intervals[i][1] << endl;
          merged[j] = true;
          j++;
        } else {
          i = j;
          break;
        }
      }
      if (j == intervals.size()) {
        break;
      }
    }

    vector<vector<int>> res;
    for (int i = 0; i < intervals.size(); i++) {
      if (!merged[i]) {
        res.push_back(intervals[i]);
      }
    }
    return res;
  }
};