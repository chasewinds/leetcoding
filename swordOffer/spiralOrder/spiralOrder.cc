#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {

    if (matrix.empty() || matrix[0].empty()) {
      return vector<int>();
    }
    if (matrix.size() == 1) {
      return matrix[0];
    }

    if (matrix[0].size() == 1) {
      vector<int> res;
      for (auto row: matrix) {
        res.push_back(row[0]);
      }
      return res;
    }

    int h = matrix.size();
    int w = matrix[0].size();


    int layer = 1;
    int row = 0;
    int col = 0;
    int direction = 0;
    vector<int> res;

    int tx = 0;
    int ty = 0;
    if (w % 2 == 0) {
      tx = (w + 1) / 2;
    } else {
      tx = w / 2;
    }
    if (h % 2 == 0) {
      ty = (h + 1) / 2;
    } else {
      ty = h / 2;
    }
    while (!(col == tx && row == ty)) {
//      cout << "row: " << row << "col: " << col << "dir: " << direction <<
endl;
//      cout << "matrix[row][col]: " << matrix[row][col] << endl;

      res.push_back(matrix[row][col]);
      if (direction == 0) {
        if (col == w - layer) {
          direction++;
        } else {
          col++;
        }
      }
      if (direction == 1) {
        if (row == h - layer) {
          direction++;
        } else {
          row++;
        }
      }
      if (direction == 2) {
        if (col == layer - 1) {
          direction++;
          layer++;
        } else {
          col--;
        }
      }
      if (direction == 3) {
        if (row == layer - 1) {
          direction = 0;
          col++;
        } else {
          row--;
        }
      }
    }
//    cout << "row: " << row << " col: " << col << endl;
    res.push_back(matrix[row][col]);
    if (matrix[0].size() == 2) {
      res.push_back(matrix[row][col - 1]);
    }

    return res;
  }
};
 */

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {

    if (matrix.empty() || matrix[0].empty()) {
      return vector<int>();
    }

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int down = matrix.size() - 1;
    vector<int> res;
    while (left <= right && top <= down) {
      for (int col = left; col <= right; col++) {
        res.push_back(matrix[top][col]);
      }
      for (int row = top + 1; row <= down; row++) {
        res.push_back(matrix[row][right]);
      }
      if (left < right && top < down) {
        for (int col = right - 1; col >= left; col--) {
          res.push_back(matrix[down][col]);
        }
        for (int row = down - 1; row > top; row--) {
          res.push_back(matrix[row][left]);
        }
      }

      left++;
      right--;
      top++;
      down--;
    }

    return res;
  }
};

int main() {
  auto s = new Solution;
  vector<vector<int>> matrix = {
      {1, 2, 3, 4},
      {5, 6, 7, 8},
      {9, 10, 11, 12},
      {13, 14, 15, 16},
  };
  //  vector<vector<int>> matrix = {
  //      {1, 2},
  //      {3, 4},
  //  };
//    vector<vector<int>> matrix = {
//        {6, 7, 9},
//    };
  vector<int> res = s->spiralOrder(matrix);
  for (auto x : res) {
    cout << x << " ";
  }
  return 0;
}