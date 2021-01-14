#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int ci = 0;
        int h = board.size();
        int w = board[0].size();
        vector<vector<bool>> visited;
        for (int i = 0; i < h; i++) {
            visited.push_back(vector<bool>(w));
        }

        vector<pair<int, int>> q;
        bool bnt = false;
        for (int i = 0; i < h && bnt != true; i++) {
            for (int j = 0; j < w && bnt != true; j++) {
                if (board[i][j] == word[ci]) {
                    q.push_back({i, j});
                    bnt = true;
                }
            }
        }
        
        
        while (!q.empty()) {
            vector<pair<int, int>> next;
            while (!q.empty()) {
                auto top = q.back();
                q.pop_back();
               
                // cout << "potencial: " << top.first << " " << top.second << endl;
                if (board[top.first][top.second] != word[ci]) {
                    continue;
                }

                ci++;
                visited[top.first][top.second] = true;

                if (ci == word.size() - 1 && word[ci] == word[word.size() - 1]) {
                    return true;
                }
                if (int x = top.first - 1; x >= 0 && !visited[x][top.second]) {
                    next.push_back({x, top.second});
                }
                if (int x = top.first + 1; x < h && !visited[x][top.second]) {
                    next.push_back({x, top.second});
                }
                if (int y = top.second - 1; y >= 0 && !visited[top.first][y]) {
                    next.push_back({top.first, y});
                }
                if (int y = top.second + 1; y < w && !visited[top.first][y]) {
                    next.push_back({top.first, y});
                }
                if (ci == 2) {
                    for (auto x: next) {
                        cout <<  x.first << " "  << x.second << endl; 
                    }
                }
            }
            q = next;
        }

        return false;
    }
};
*/

class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {

            int h = board.size();
            int w = board[0].size();
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (dfs(board, i, j, word, 0, h, w)) {
                        return true;
                    }
                }
            }

            return false;
        }

        bool dfs(vector<vector<char>>& board, int x, int y, string word, int i, int h, int w) {

            if (x < 0 || x >= h || y < 0 || y >= w || board[x][y] != word[i]) {
                return false;
            }

            if (i == word.size() - 1) {
                return true;
            }

            board[x][y] = '\'';
            bool r1 = dfs(board, x + 1, y, word, i + 1, h, w);
            bool r2 = dfs(board, x - 1, y, word, i + 1, h, w);
            bool r3 = dfs(board, x, y + 1, word, i + 1, h, w);
            bool r4 = dfs(board, x, y - 1, word, i + 1, h, w);
            board[x][y] = word[i];

            return r1 || r2 || r3 || r4;
        }
};

int main() {
    cout << "m" << endl;
    return 0;
}