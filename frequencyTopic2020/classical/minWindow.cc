#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
// burst force, when 265 / 266 cases, TLE :) 调通这个暴搜真头大....

class Solution {
 public:
  string minWindow(string s, string t) {
    if (s.empty() || t.empty()) {
      return "";
    }
    if (s.size() == 1) {
      if (s == t) {
        return s;
      }
      return "";
    }
    unordered_map<char, int> memo;
    for (char& c : t) {
      if (auto it = memo.find(c); it != memo.end()) {
        it->second++;
      } else {
        memo.insert({c, true});
      }
    }
    auto x = memo.find('a');
    // cout << "a:" << x->second <<endl;

    vector<pair<int, int>> potensal;
    bool stop = false;
    int shortest = s.size();
    int i = 0;
    while (i < s.size() && !stop) {
      unordered_map<char, int> local;
      local = memo;
      if (auto it = local.find(s[i]); it != local.end()) {
        if (it->second == 1) {
          local.erase(it->first);
        } else {
          it->second--;
        }
      }
      if (local.empty()) {
        //   cout << "match" << endl;
        //   cout << "s[i]" << s[i] << endl;
          string res = "";
          res.push_back(s[i]);
          return res;
        }

      int j = i + 1;
      if (j == s.size()) {
          break;
      }
      while (j < s.size()) {
        if (auto it = local.find(s[j]); it != local.end()) {
          if (it->second == 1) {
            local.erase(it->first);
          } else {
            it->second--;
          }
        }
        if (local.empty()) {
          potensal.push_back({i, j});
          shortest = min(j - i, shortest);
          i++;
        //   cout << "normal barek" << endl;
          break;
        }
        j++;
        if (j == s.size()) {
            // cout << "break form this" << endl;
          stop = true;
          break;
        }
      }
    }
    // cout << potensal[0].first << potensal[0].second << endl;
    if (!potensal.empty()) {
      for (auto x : potensal) {
        if (x.second - x.first == shortest) {
          string res = "";
          for (int i = x.first; i <= x.second; i++) {
            res.push_back(s[i]);
          }
          return res;
        }
      }
    }
    return "";
  }
};
*/

// slide window
class Solution {
 public:
  string minWindow(string s, string t) {
    unordered_map<char, int> target, cur;
    for (auto c : t) {
      target[c]++;
    }

    int rp = -1;
    int lp = 0;
    int resFrom = -1;
    int len = s.size();
    while (rp < s.size()) {
      cout << "x" << endl;
      rp++;
      if (target.find(s[rp]) != target.end()) {
        cur[s[rp]]++;
      }
      while (satisfy(cur, target) && lp <= rp) {
        cout << "y" << endl;
        if (rp - lp + 1 < len) {
          len = rp - lp + 1;
          resFrom = lp;
        }
        if (target.find(s[lp]) != target.end()) {
          cur[s[lp]]--;
        }
        lp++;
      }
    }
    return resFrom == -1 ? "" : s.substr(resFrom, len);
  }

  bool satisfy(unordered_map<char, int> cur, unordered_map<char, int> target) {
    for (auto x : target) {
      if (cur[x.first] < x.second) {
        return false;
      }
    }
    return true;
  }
};


class Solution {
 public:
  unordered_map <char, int> ori, cnt;

  bool check() {
    for (const auto &p: ori) {
      if (cnt[p.first] < p.second) {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t) {
    for (const auto &c: t) {
      ori[c]++;
    }

    int l = 0, r = -1;
    int len = s.size(), ansL = -1;

    while (r < int(s.size())) {
      cout << "x" << endl;
      r++;
      if (ori.find(s[r]) != ori.end()) {
        cnt[s[r]]++;
      }
      while (check() && l <= r) {
        cout << "y" << endl;
        if (r - l + 1 < len) {
          len = r - l + 1;
          ansL = l;
        }
        if (ori.find(s[l]) != ori.end()) {
          cnt[s[l]]--;
        }
        l++;
      }
    }

    return ansL == -1 ? string() : s.substr(ansL, len);
  }
};