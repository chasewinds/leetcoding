

/*
 * 整数溢出
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0) {
            return 0;
        }
        long long res = mul(n);
        int count = 0;
        while (res % 10 == 0) {
            res /= 10;
            count++;
        }
        return count;
    }

    long long mul(long long n) {
        if (n == 1) {
            return n;
        }
        return n * mul(n - 1);
    }
};
*/

class Solution {
public:
    int trailingZeroes(int n ) {
        int count = 0;
        while (n % 5 == 0) {
            n /= 5;
            count++;
        }
        return count;
    }
};