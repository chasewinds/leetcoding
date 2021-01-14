#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> triangle;
    for (int i = 0; i < rowIndex + 1; i++) {
      vector<int> row;
      row.reserve(rowIndex + 1);
      for (int j = 0; j < rowIndex + 1; j++) {
        row.push_back(0);
      }
      triangle.push_back(row);
    }
    return calcRowLayerByLayer(triangle, 0, rowIndex);
  }

  vector<int> calcRowLayerByLayer(vector<vector<int>> triangle, int curLayer,
                                  int targetLayer) {
    int x = curLayer;
    for (int y = 0; y < curLayer + 1; y++) {
      if (x == 0 || y == 0) {
        triangle[x][y] = 1;
        continue;
      }
      int sum = triangle[x - 1][y - 1] + triangle[x - 1][y];
      if (sum == 0) {
        sum = 1;
      }
      triangle[x][y] = sum;
    }
    if (curLayer == targetLayer) {
      return triangle[targetLayer];
    }
//    printTriangle(triangle);
    return calcRowLayerByLayer(triangle, curLayer + 1, targetLayer);
  }

//  void printTriangle(vector<vector<int>> triangle) {
//    for (vector<int> row: triangle) {
//      for (int x: row) {
//        cout << x;
//      }
//      cout << endl;
//    }
//  }
};

int main() {
  auto s = new Solution();
  for (int x : s->getRow(10)) {
    cout << "ele: " << x << endl;
  }
  return 0;
}