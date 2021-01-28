#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {

        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int h = grid.size();
        int w = grid[0].size();
        vector<vector<int>> dp = vector<vector<int>>(h);
        for (int i = 0; i < dp.size(); i++) {
            dp[i] = vector<int>(w, -1);
        }
        dp[0][0] = grid[0][0];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                // cout << "i: " << i << " j: " << j << " grid " << grid[i][j] << endl;
                if (dp[i][j] == -1) {
                    // cout << "up: " << up << " left: " << left << " min() "<< min(dp[up][j], dp[i][left]) << endl;
                    if (i == 0 && j == 0) {
                        continue;
                    }
                    if (i == 0) {
                        dp[i][j] = dp[i][j - 1] + grid[i][j];
                    } else if (j == 0) {
                        dp[i][j] = dp[i - 1][j] + grid[i][j];
                    } else {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                    }
                }
            }
        }

        // for (int i = 0; i < dp.size(); i++) {
        //     for (int j = 0; j < dp[0].size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp.back().back();
    }
};