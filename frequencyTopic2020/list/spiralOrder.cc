#include <iostream>
#include <vector>

using namespace std;

//
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
      return vector<int>();
    }
    int h = matrix.size();
    int w = matrix[0].size();
    int row = 0;
    int col = 0;
    int layer = 0;
    vector<int> res;
    while (h - layer - 1 > 0 || w - layer - 1 > 0) {
      if (w - layer - 1 >= 0) {
        for (; col < w - layer - 1; col++) {
          cout << matrix[row][col] << "x(" << row << ", " << col << ")" << endl;
          res.push_back(matrix[row][col]);
        }
      }

      cout << "h - layer - 1: " << h - layer - 1 << endl;
      if (h - layer - 1 >= 0) {
        for (; row < h - layer - 1; row++) {
          cout << matrix[row][col] << "y(" << row << ", " << col << ")" << endl;
          res.push_back(matrix[row][col]);
        }
      }

      for (; col > layer; col--) {
        cout << matrix[row][col] << "z(" << row << ", " << col << ")" << endl;
        res.push_back(matrix[row][col]);
      }
      //   cout << "before" << endl;
      layer++;
      //   cout << "after" << endl;
      for (; row > layer; row--) {
        cout << matrix[row][col] << "k(" << row << ", " << col << ")" << endl;
        res.push_back(matrix[row][col]);
      }
    }
    // cout << "row: " << row << " col: " << col << endl;
    // res.push_back(matrix[row][col]);
    return res;
  }
};