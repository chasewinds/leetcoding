#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int totalNQueens(int n) {
    if (n <= 0 ) {
      return 0;
    }

    vector<vector<bool>> board;
    for (int i = 0; i < n; i++) {
      board.emplace_back(false);
    }
    int res = 0;

    backTracingNQueens(0, 0, res, n, board);
    return res;
  }

  bool willBeEat(int row, int col, vector<vector<bool>> board) {
    if (board[row][col]) {
      return true;
    }

    int maxIdx = board.size() - 1;
    for (int i = 0; i < col; i++) {
      if (board[row][i]) {
        return true;
      }
      if (board[i][col]) {
        return true;
      }
      if (row - i >= 0 && col - i >= 0 && board[row - i][col - i]) {
         return true;
      }
      if (row - i >= 0 && col + i <= maxIdx && board[row - i][col + i]) {
        return true;
      }
      if (row + i <= maxIdx && col - i >= 0 && board[row + i][col - i]) {
        return true;
      }
      if (row + i <= maxIdx && col + i <= maxIdx && board[row + i][col + i]) {
        return true;
      }
    }

    return false;
  }

  void placeQueen(int row, int col, vector<vector<bool>>& board) {
    board[row][col] = true;
  }

  void removeQueen(int row, int col, vector<vector<bool>>& board) {
    board[row][col] = false;
  }

  void backTracingNQueens(int row, int col, int & nsolution, int qleft, vector<vector<bool>>& board) {
    if (qleft == 0) {
      nsolution++;
      return;
    }
    if (willBeEat(row, col, board)) {
      return;
    }


    placeQueen(row, col, board);
    int nextRow, nextCol;
    if (col == board[0].size() - 1) {
      if (row == board.size() - 1) {
        return;
      }
      nextCol = 0;
      nextRow = row + 1;
    } else {
      nextRow = row;
      nextCol = col + 1;
    }
    backTracingNQueens(nextRow, nextCol, nsolution, qleft - 1, board);
    // when back tracing, we need to remove placed queen
    removeQueen(row, col, board);
  }
};

int main() {
  cout << "nqueen" << endl;
  auto s = new Solution;
  cout << s->totalNQueens(4);
  return 0;
}