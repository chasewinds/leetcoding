#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    backTrackSudoku(0, 0, board);
  }

  bool backTrackSudoku(int row, int col, vector<vector<char>>& board) {

    if (row == 9) {
      return true;
    }

    if (col == 9) {
      return backTrackSudoku(row + 1, 0, board);
    }
    if (board[row][col] != '.') {
      return backTrackSudoku(row, col + 1, board);
    }

    for (int i = 1; i <= 9; i++) {
      char x = '0' + i;
      if (!isValid(x, row, col, board)) {
        continue;
      }
      board[row][col] = x;
      // this is key point!you need to stop once you got solution!
      // or you will back track and go back to where you start.
      if (backTrackSudoku(row, col, board)) {
        return true;
      }
      board[row][col] = '.';
    }

    return false;
  }

  bool isValid(char number, int row, int col, vector<vector<char>>& board) {

    // check row and col repeat
    for (int i = 0; i < 9; i++) {
      if (board[i][col] == number) {
        return false;
      }
      if (board[row][i] == number) {
        return false;
      }
    }

    // check 3 X 3 cell repeat
    for (int i = cellRange(row).first; i <= cellRange(row).second; i++) {
      for (int j = cellRange(col).first; j <= cellRange(col).second; j++) {
        if (board[i][j] == number) {
          return false;
        }
      }
    }

    return true;
  }

  pair<int, int> cellRange(int idx) {
    switch (idx / 3) {
      case 0:
        return pair<int, int>(0, 2);
      case 1:
        return pair<int, int>(3, 5);
      case 2:
        return pair<int, int>(6, 8);
    }
  }

  void printMatrix(vector<vector<char>>& metrix) {
    for (auto row : metrix) {
      for (auto ele : row) {
        cout << ele << ",";
      }
      cout << endl;
    }
  }
};

int main() {
  vector<vector<char>> inputBoard = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };

  auto s = new Solution;
//  cout << s->isValid(0, 2, inputBoard) << endl;

  s->solveSudoku(inputBoard);
  s->printMatrix(inputBoard);
  return 0;
}