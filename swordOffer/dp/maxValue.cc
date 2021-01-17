#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxValue(vector<vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }
    vector<vector<int>> dp;
    for (int i = 0; i < grid.size(); i++) {
      dp.push_back(vector<int>(grid.size(), 0));
    }

    bfs(grid, dp, 0, 0);
    return dp.back().back();
  }

  void bfs(vector<vector<int>>& grid, vector<vector<int>>& dp, int row,
           int col) {
    //   cout << "row: " << row << " col: " <<col << endl;
    if (row >= grid.size() || col >= grid[0].size()) {
      return;
    }

    if (row == 0 && col == 0) {
      dp[row][col] = grid[row][col];
    } else if (row == 0 && col != 0) {
      dp[row][col] = dp[row][col - 1] + grid[row][col];
    } else if (row != 0 && col == 0) {
      dp[row][col] = dp[row - 1][col] + grid[row][col];
    } else {
      dp[row][col] = max(dp[row - 1][col], dp[row][col - 1]) + grid[row][col];
    }
    bfs(grid, dp, row + 1, col);
    bfs(grid, dp, row, col + 1);
  }
};
