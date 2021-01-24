#include <iostream>
#include <vector>
#include <string>
#incldue <unordered_map>

using namespace std;

class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.empty()) {
      return {};
    }
    unordered_map<string, int> memo;
    vector<vector<string>> res;
    for (int i = 0; i < strs.size(); i++) {
      string temp = strs[i];
      sort(temp.begin(), temp.end());
      if (auto it = memo.find(temp); it != memo.end()) {
        res[it->second].push_back(strs[i]);
      } else {
        res.push_back(vector<string>{strs[i]});
        memo.insert({temp, res.size() - 1});
      }
    }
    return res;
  }
};

