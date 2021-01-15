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
  int maxDepth(TreeNode *root) {

    if (root == nullptr) {
      return 0;
    }

    int res = 0;
    vector<TreeNode*> stk;
    stk.push_back(root);
    while (!stk.empty()) {
      vector<TreeNode*> next;
      while (!stk.empty()) {
        auto top = stk.back();
        stk.pop_back();
        if (top->left != nullptr) {
          next.push_back(top->left);
        }
        if (top->right != nullptr) {
          next.push_back(top->right);
        }
      }
      stk = next;
      res++;
    }

    return res;
  }
};
