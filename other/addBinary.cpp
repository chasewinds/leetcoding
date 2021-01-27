#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int toInt(char x) {
        if (x == '1') {
            return 1;
        }
        return 0;
    }


    string addBinary(string a, string b) {
        stack<int> sa;
        stack<int> sb;
        stack<char> res;
        for (char& x: a) {
            sa.push(toInt(x));
        }
        for (char& y: b) {
            sb.push(toInt(y));
        }
        int bit = 0;
        while (sa.size() != 0 || sb.size() != 0) {
            int x = 0, y = 0;
            if (sa.size() != 0) {
                x = sa.top();
                sa.pop();
            }
            if (sb.size() != 0) {
                y = sb.top();
                sb.pop();
            }
            int sum = x + y + bit;
            switch (sum) {
            case 0:
                res.push('0');
                bit = 0;
                break;
            case 1:
                res.push('1');
                bit = 0;
                break;
            case 2:
                res.push('0');
                bit = 1;
                break;
            case 3:
                res.push('1');
                bit = 1;
                break;
            default:
                cout << "go to default" << endl;
            }
        }
        if (bit != 0) {
            res.push('1');
        }

        string str;
        while (res.size() != 0) {
            char c = res.top();
            res.pop();
            string s(1, c);
            str += s;
        }
        return str;
    }
};

int main() {
    auto s = new Solution;
    string res = s->addBinary("1010", "1011");
    cout << res;
    return 0;
}