#include <iosteam>
#include <vector>

using namespace std;

class Solution {
    public:
        int movingCount(int m, int n, int k) {
            
            int res = 0;
            vector<pair<int, int>> steps;
            steps.push_back({0, 0});
            vector<vector<bool>> visited;
            for (int i = 0; i < m; i++) {
                visited.push_back(vector<bool>(n));
            }

            while (!steps.empty()) {
                vector<pair<int, int>> next;
                while (!steps.empty()) {
                    auto top = steps.back();
                    steps.pop_back();
                    if (top.first < 0 || top.first > m - 1 || top.second < 0 || top.second > n - 1 || visited[top.first][top.second]) {
                        continue;
                    }
                    if (!canAccess(top.first, top.second, k)) {
                        continue;
                    }
                    res++;
                    visited[top.first][top.second] = true;
                    next.push_back({top.first + 1, top.second});
                    next.push_back({top.first, top.second + 1});
                }
                steps = next;
            }

            return res;
        }

        bool canAccess(int i, int j, int k) {
            return (i/10 + i%10 + j/10 + j%10) <= k;
        }

/*
        bool canAccess(int x, int y, int k) {

            cout << "x " << x << " y " << y << endl;
            int sum = 0;
            if (x >= 10) {
                while (x / 10 != 0) {
                    sum += x % 10;
                    x /= 10;
                }
            } else {
                sum += x;
            }
            
            if (y >= 10) {
                while (y / 10 != 0) {
                    sum += y % 10;
                    y /= 10;
                }
            } else {
                sum += y;
            }
            
            cout << "sum: " << sum << endl;
            if (sum == k) {
                return true;
            }

            return false;
        }
        */
};