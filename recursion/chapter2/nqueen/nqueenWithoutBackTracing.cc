#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Board {
 public:
  int size;
  Board(int size) : size(size) {}

  vector<vector<int>> nQueenSolutions() {
    vector<vector<int>> res;
    dfsNQueenSolutions(vector<int>{}, res);
    return res;
  }

  void printList(vector<int> list) {
    for (int x: list) {
      cout << x;
    }
    cout << endl;
  }

 private:

  // rowToCol: queen layout, i th row queen placed on rowToCol[i] th col.
  void dfsNQueenSolutions(vector<int> rowToCol, vector<vector<int>>& res) {

    // check if we got solution
    if (rowToCol.size() == this->size) {
      res.push_back(rowToCol);
      rowToCol.clear();
      return;
    }

    // try place queen on every row
    for (int col = 0; col < this->size; col++) {
      if (isSafe(col, rowToCol)) {
        rowToCol.push_back(col); // row add 1 automatically by push_back
        dfsNQueenSolutions(rowToCol, res);
        rowToCol.pop_back();
      }
    }
  }

  bool isSafe(int col, vector<int> rowToCol) {
    int curRowIdx = rowToCol.size();
    // every queen add a row, so loop through queen idx = loop through row
    for (int row = 0; row < curRowIdx; row++) {
      if (int c = rowToCol[row]; c == col) {
        return false; // one queen had already placed in this col, will be eat.
      }

      int verticalDistance = curRowIdx - row;
      int horizontalDistance = abs(col - rowToCol[row]);
      // one queen placed in diagonal direction
      if (verticalDistance == horizontalDistance) {
        return false;
      }
    }

    return true;
  }
};

int main() {
  auto board = new Board(4);
  for (auto list: board->nQueenSolutions()) {
    board->printList(list);
  }
  return 0;
}