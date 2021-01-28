#include <isotream>
#include <string>

using namespace std;


class Solution {
public:
    int minPath;

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if (m * n == 0) {
            return m + n;
        }

        vector<vector<int>> dp = vector<vector<int>>(m + 1);
        for (int i = 0; i <= m; i++) {
            dp[i] = vector<int>(n + 1, 0);
        }
        for (int i = 0; i < m + 1; i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < n + 1; i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                int left = dp[i - 1][j] + 1;
                int up = dp[i][j - 1] + 1;
                int left_up = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    left_up++;
                }
                dp[i][j] = min(left, min(up, left_up));
            }
        }
        return dp[m][n];
    }
};


/*
// backtrack 指数级复杂度
class Solution {
public:
    int minPath;

    int minDistance(string word1, string word2) {
        if (word1.empty()) {
            return word2.size();
        }
        if (word2.empty()) {
            return word1.size();
        }

        minPath = INT_MAX;
        search(word1, word2, 0);
        return minPath;
    }

    void search(string word1, string word2, int path) {
        if (word1 == word2) {
            minPath = min(minPath, path);
            return;
        }
        if (word1.empty()) {
            minPath = min(minPath, path + word2.size());
            return;
        }
        int p1 = 0;
        int p2 = 0;
        while (p1 < word1.size() && p2 < word2.size() && word1[p1] == word2[p2]) {
            p1++;
            p2++;
        }

        char temp = word1[p1];
        // try delete
        word1.erase(p1);
        search(word1, word2, path + 1);
        word1.insert(p1, temp);

        // try add
        word1.insert(p1, word2[p2]);
        search(word1, word2, path + 1);
        word1.erase(p1);

        // try modify
        word1[p1] = word2[p2];
        search(word1, word2, path + 1);
        word1[p1] = temp;
    }
};
*/