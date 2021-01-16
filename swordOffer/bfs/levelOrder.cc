#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  vector<int> levelOrder(TreeNode *root) {
    vector<int> res;
    bfs(res, vector<TreeNode *>{root});
    return res;
  }

  void bfs(vector<int> &res, vector<TreeNode *> list) {
    if (list.empty()) {
      return;
    }
    vector<TreeNode *> next;
    for (auto x : list) {
      if (x == nullptr) {
        continue;
      }
      res.push_back(x->val);
      next.push_back(x->left);
      next.push_back(x->right);
    }
    bfs(res, next);
  }
};