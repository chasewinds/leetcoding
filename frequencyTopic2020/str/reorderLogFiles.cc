#include <iostream>
#include <string>

using namespace std;

// 注意因为数字要保持原有顺序，所以要用稳定排序，sort是快排，不稳定
class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    if (logs.empty()) {
      return {};
    }
    // bubble sort
    for (int i = 0; i < logs.size(); i++) {
      for (int j = 0; j < logs.size() - 1; j++) {
        if (!less(logs[j], logs[j + 1])) {
          swap(logs[j], logs[j + 1]);
        }
      }
    }
    return logs;
  }

  static bool less (const string& s1, const string& s2) {
    int idx1 = 0;
    while (s1[idx1] != ' ') {
      idx1++;
    }
    idx1++;
    int idx2 = 0;
    while (s2[idx2] != ' ') {
      idx2++;
    }
    idx2++;
    bool num1 = s1[idx1] >= '0' && s1[idx1] <= '9';
    bool num2 = s2[idx2] >= '0' && s2[idx2] <= '9';
    //   cout << num1 << " " << num2 << endl;
    if ((!num1 && num2) || (num1 && num2)) {
      return true;
    } else if ((num1 && !num2) ) {
      return false;
    } else {
      // both string
      string x = s1.substr(idx1, s1.size() - 1);
      string y = s2.substr(idx2, s2.size() - 1);
      if (x != y) {
        return x < y;
      }
      x = s1.substr(0, idx1);
      y = s2.substr(0, idx2);
      return x <= y;
    }
  }
};

/*
class Solution {
 public:
  vector<string> reorderLogFiles(vector<string>& logs) {
    if (logs.empty()) {
      return {};
    }
    // stable_sort
    stable_sort(logs.begin(), logs.end(), less);
    return logs;
  }

  static bool less (const string& s1, const string& s2) {
      int idx1 = 0;
      while (s1[idx1] != ' ') {
        idx1++;
      }
      idx1++;
      int idx2 = 0;
      while (s2[idx2] != ' ') {
        idx2++;
      }
      idx2++;
      bool num1 = s1[idx1] >= '0' && s1[idx1] <= '9';
      bool num2 = s2[idx2] >= '0' && s2[idx2] <= '9';
    //   cout << num1 << " " << num2 << endl;
      if ((!num1 && num2)) {
        return true;
      } else if ((num1 && !num2)  || (num1 && num2)) {
        return false;
      } else {
        // both string
        string x = s1.substr(idx1, s1.size() - 1);
        string y = s2.substr(idx2, s2.size() - 1);
        if (x != y) {
          return x < y;
        }
        x = s1.substr(0, idx1);
        y = s2.substr(0, idx2);
        return x <= y;
      }
    }
};
 */