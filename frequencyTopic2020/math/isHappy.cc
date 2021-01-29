#include <iostream>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        queue<int> q;
        inQ(n, q);
        unordered_set<int> memo;
        while (!q.empty()) {
            int step = 0;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                int top = q.front();
                q.pop();
                step += pow(top, 2);
            }
            if (step == 1) {
                return true;
            }
            if (memo.count(step) > 0) {
                return false;
            }
            if (step > 0) {
                memo.insert(step);
                inQ(step, q);
            }
        }
        return false;
    }

    void inQ(int n, queue<int> &q) {
        while (n > 0) {
            int x = n % 10;
            n /= 10;
            q.push(x);
        }
    }
};