#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.size() == 0 || s.size() == 1) {
            return;
        }
        reverseFromBiDirection(s, 0, s.size() - 1);
    }

    void reverseFromBiDirection(vector<char> &s, int left, int right) {
        if (left >= right) {
            return;
        }
        swap(s[left], s[right]);
        cout << "swap once" << endl;
        left++;
        right--;
        reverseFromBiDirection(s, left, right);
    }
};

int main() {
    cout << "hi" << endl;
    auto s = new Solution;
    vector<char> input = {'h', 'i'};
    s->reverseString(input);
    for (char c: input) {
        cout << c << endl;
    }

    return 0;
}