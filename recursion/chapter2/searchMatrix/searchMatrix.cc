#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }
    // matrix[y][x] 是先y后x的！先查行后查列！！
    return searchRec(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1,
                     target);
  }

  bool searchRec(vector<vector<int>>& matrix, int px1, int py1, int px2,
                 int py2, int target) {
//        cout << "p1: (" << px1 << "," << py1 << "), p2: (" << px2 << "," <<
//        py2
//             << ")" << endl;
    if (px1 > px2 || py1 > py2) {
      return false;
    }
    if (target < matrix[py1][px1] || target > matrix[py2][px2]) {
      return false;
    }
    int mx = px1 + (px2 - px1) / 2;
    int my = py1 + (py2 - py1) / 2;


    int row = py1;
    while (row <= py2 && matrix[row][mx] <= target) {
      if (matrix[row][mx] == target) {
        return true;
      }
      row++;
    }

    int col = px1;
    while (col <= px2 && matrix[my][col] <= target) {
      if (matrix[my][col] == target) {
        return true;
      }
      col++;
    }


    return searchRec(matrix, px1, row, mx - 1, py2, target) || searchRec(matrix,
mx + 1, px1, px2, row - 1, target);
  }
};
 */

// binary search
class Solution {
 public:
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
      return false;
    }

    int h = matrix.size();
    int w = matrix[0].size();

    int left = 0;
    int right = w - 1;
    while (left < w && right > 0 && left <= right) {
      int mid = (left + right) / 2;
      if (matrix[0][mid] > target) {
        right = mid - 1;
      } else if (matrix[0][mid] < target) {
        left = mid + 1;
      } else {
        return true;
      }
    }

    int high = 0;
    int low = h - 1;
    while (high < h && low > 0 && high <= low) {
      int mid = (high + low) / 2;
      if (matrix[mid][left] < target) {
        high = mid + 1;
      } else if (matrix[mid][left] > target) {
        low = mid - 1;
      } else {
        return true;
      }
    }

    high = 0;
    low = h - 1;
    while (high < h && low > 0 && high <= low) {
      int mid = (high + low) / 2;
      if (matrix[mid][right] < target) {
        high = mid + 1;
      } else if (matrix[mid][right] > target) {
        low = mid - 1;
      } else {
        return true;
      }
    }

    return false;
  }
};

int main() {
  auto s = new Solution;
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };
//  vector<vector<int>> matrix = {
//      {1, 4},
//      {2, 5},
//  };
  cout << s->findNumberIn2DArray(matrix, 20) << endl;
  return 0;
}