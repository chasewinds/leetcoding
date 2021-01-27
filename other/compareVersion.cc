#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1.empty() && version2.empty()) {
            return 0;
        }
        if (version1.empty()) {
            return -1;
        }
        if (version2.empty()) {
            return 1;
        }
        int p1 = 0;
        int p2 = 0;
        while (p1 < version1.size() && p2 < version2.size()) {
            while (p1 < version1.size() && version1[p1] == '0') {
                p1++;
            }
            while (p2 < version2.size() && version2[p2] == '0') {
                p2++;
            }
            cout << "p1: " << p1 << " v " << version1[p1] << " p2: " << p2  << " v " << version2[p2]<< endl;
            bool p1dot =  version1[p1] == '.';
            bool p2dot = version1[p2] == '.';
            char c1 = p1dot ? '0' : version1[p1];
            char c2 = p2dot ? '0' : version1[p2];
            cout << "c1: " << c1 << " c2: " << c2 << endl;
            if (c1 == c2) {
                if ((p1dot && p2dot) || (!p1dot && !p2dot)) {
                    p1++;
                    p2++;
                }
                if (p1dot) {
                    p2++;
                }
                if (p2dot) {
                    p1++;
                }
            } else if (c1 < c2) {
                return -1;
            } else {
                return 1;
            }
        }
        if (p1 == version1.size() && p2 == version2.size()) {
            return 0;
        }
        if (p1 < version1.size())  {
            return 1;
        }
        return -1;
    }
};