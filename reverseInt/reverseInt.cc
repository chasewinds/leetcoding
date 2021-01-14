#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int tail = x % 10;
            if (res >= INT_MAX / 10 || (res == INT_MAX && tail > 7)) {
                return 0;
            }
            if (res <= INT_MIN / 10 || (res == INT_MIN && tail < -8)) {
                return 0;
            }
            res = res * 10 + tail;
            x /= 10;
        }
        return res;
    }
};

int main() {
//    cout << "hi" << endl;
    auto s = new Solution;
//    cout << s->reverse(1534236469) << endl;
    cout << s->reverse(1463847412) << endl;

    return 0;
}