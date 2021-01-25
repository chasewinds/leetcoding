#include <iostream>

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
  int res;
  int maxPathSum(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    res = root->val;
    searchSum(root);
    return res;
  }

  void searchSum(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    int sum = root->val;
    sum += max(0, searchBrach(root->left));
    sum += max(0, searchBrach(root->right));
    res = max(res, sum);
    searchSum(root->left);
    searchSum(root->right);
    return;
  }

  int searchBranch(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int m = 0;
    if (node->left != nullptr) {
      m = max(m, searchBrach(node->left));
    }
    if (node->right != nullptr) {
      m = max(m, searchBrach(node->right));
    }
    // cout << m << endl;
    return m + node->val;
  }
};