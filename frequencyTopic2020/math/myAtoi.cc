#include <iostream>
#include <string>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        if (s.empty()) {
            return 0;
        }
        int p = 0;
        while (s[p] == ' ') {
            p++;
        }
        bool positive = true;
        if (s[p] == '-') {
            positive = false;
            p++;
        } else if (s[p] == '+') {
            p++;
        }
        int res = 0;
        int upbound = INT_MAX / 10;
        while (p < s.size()) {
            if (!isdigit(s[p])) {
                if (res != 0 && !positive) {
                    res = -res;
                }
                return res;
            }
            int n = s[p] - '0';
            if ((res > upbound || (res == upbound && n > 7))) {
                if (positive) {
                    return INT_MAX;
                }
                return INT_MIN;
            }
            res = res * 10 + n;
            p++;
        }
        if (res != 0 && !positive) {
            res = -res;
        }
        return res;
    }
};