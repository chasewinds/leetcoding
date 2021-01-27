#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int h;
    int w;

    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        h = board.size();
        w = board[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (backtrack(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool backtrack(vector<vector<char>> &board, int i, int j, string word, int idx) {
        if (board[i][j] != word[idx]) {
            return false;
        }
        if (idx == word.size() - 1) {
            return true;
        }
        board[i][j] = '0';
        bool res = fales;
        if (i - 1 >= 0 && board[i - 1][j] != '0') {
            res || = backtrack(board, i - 1, j, word, idx + 1);
        }
        if (i + 1 < h && board[i + 1][j] != '0') {
            res || = backtrack(board, i + 1, j, word, idx + 1);
        }
        if (j - 1 >= 0 && board[i][j - 1] != '0') {
            res || = backtrack(board, i, j - 1, word, idx + 1);
        }
        if (j + 1 < w && board[i][j + 1] != '0') {
            res || = backtrack(board, i, j + 1, word, idx + 1);
        }
        board[i][j] = word[idx];
        return res;
    }
};