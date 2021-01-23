#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// runtime 5.25% / memo 5.05%, bad solution.
class Solution {
 public:
  string mostCommonWord(string paragraph, vector<string>& banned) {

    if (paragraph.empty()) {
      return "";
    }

    unordered_map<string, bool> bannedSet;
    for (string x: banned) {
      bannedSet[x] = true;
    }
    int p = 0;
    unordered_map<string, int> memo;
    int mostF = 0;
    while (p < paragraph.size()) {
      //   cout << "p " << p << endl;
      while (p < paragraph.size() && !isWord(paragraph[p])) {
        p++;
      }
      int q = p + 1;
      while (q < paragraph.size() && isWord(paragraph[q])) {
        q++;
      }

      string word = "";
      for (int i = p; i <= paragraph.size() - 1 && i < q; i++) {
        word.push_back(tolower(paragraph[i]));
      }

      //   cout << "word: " <<  word << endl;
      if (!beBanned(word, bannedSet)) {
        // cout << "!beBanned word: " <<  word << endl;
        memo[word]++;
        mostF = max(mostF, memo[word]);
      }
      p = q;
    }

    for (auto item : memo) {
      if (item.second == mostF) {
        return item.first;
      }
    }
    return "";
  }

  bool beBanned(string word, unordered_map<string, bool> bannedSet) {
    if (word == "" || word == " ") {
      return true;
    }
    if (bannedSet.empty()) {
      return false;
    }
    if (auto it = bannedSet.find(word); it != bannedSet.end()) {
      return true;
    }
    return false;
  }

  bool isWord(char c) {
    char formatted = tolower(c);
    if (formatted >= 'a' && formatted <= 'z') {
      return true;
    }
    return false;
  }
};

/*
// nb
class Solution {
public:
string mostCommonWord(string paragraph, vector<string>& banned) {
    unordered_map<string, int> cnt;
    unordered_set<string> ban;
    for (auto& w : banned) {
        ban.insert(w);
    }

    int maxcnt = 0;
    string ans;

    for (auto& c : paragraph) {
        c = isalpha(c) ? c : ' ';
    }
    // stringstream 可以用于分割被空格、制表符等符号分割的字符串
    stringstream ss(paragraph);
    string temp;
    while (ss >> temp) {
        for (auto& c : temp) {
            c = tolower(c);
        }
        if (ban.count(temp) != 0) continue;
        cnt[temp]++;
        if (cnt[temp] > maxcnt) {
            maxcnt = cnt[temp];
            ans = temp;
        }
    }
    return ans;
}
};
 */

int main() {
  auto s = new Solution;
  vector<string> banned = {"hit"};
  cout << s->mostCommonWord(
              "Bob hit a ball, the hit BALL flew far after it was hit.", banned)
       << endl;
}