#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

/*
// dfs burst force
class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    if (judge(s, t)) {
      return true;
    }
    return isSubtree(s->left, t) || isSubtree(s->right, t);
  }

  bool judge(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    if (s->val != t->val) {
      return false;
    }
    return judge(s->right, t->right) && judge(s->left, t->left);
  }
};
*/

class Solution {
 public:
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == nullptr && t == nullptr) {
      return true;
    }
    if (s == nullptr || t == nullptr) {
      return false;
    }
    long lnull = LONG_MIN;
    long rnull = LONG_MAX;
    vector<long> sf = {s->val};
    vector<long> tf = {t->val};
    firstOrder(sf, s, lnull, rnull);
    firstOrder(tf, s, lnull, rnull);

    for (auto x: sf) {
      cout << x << " ";
    }
    cout << endl;
    for (auto x : tf) {
      cout << x << " ";
    }
    return kmp(sf, tf);
  }

  void firstOrder(vector<long>& order, TreeNode* node, long lnull, long rnull) {
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr) {
      order.push_back(lnull);
    } else {
      firstOrder(order, node->left, lnull, rnull);
    }
    if (node->right == nullptr) {
      order.push_back(rnull);
    } else {
      firstOrder(order, node->right, lnull, rnull);
    }
  }

  bool kmp(vector<long> x, vector<long> y) {
    vector<int> pmt = vector<int>(y.size(), -1);
    for (int i = 1, j = -1; i < y.size(); i++) {
      while (j != -1 && y[i] != y[j + 1]) {
        j = pmt[j];
      }
      if (y[i] == y[j + 1]) {
        j++;
      }
      pmt[i] = j;
    }
    for (int i = 0, j = -1; i < x.size(); i++) {
      while (j != -1 && x[i] != y[j + 1]) {
        j = pmt[j];
      }
      if (x[i] == y[j + 1]) {
        j++;
      }
      if (j == y.size() - 1) {
        return true;
      }
    }
    return false;
  }
};