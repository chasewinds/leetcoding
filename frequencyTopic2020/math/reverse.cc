#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int n = x % 10;
            x /= 10;
            int upbound = INT_MAX / 10;
            int lowbound = INT_MIN / 10;
            if (res > upbound || (res == upbound && n > 7)) {
                return 0;
            }
            if (res < lowbound || (res == lowbound && n < -8)) {
                return 0;
            }
            res = res * 10 + n;
        }
        return res;
    }
};