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
  bool isValidBST(TreeNode *root) {
    if (root == nullptr) {
      return true;
    }
    return bfs(root->left, root->val, LONG_MIN) &&
           bfs(root->right, LONG_MAX, root->val);
  }

  bool bfs(TreeNode *node, long up, long lower) {
    if (node == nullptr) {
      return true;
    }
    if (node->val <= lower || node->val >= up) {
      return false;
    }
    return bfs(node->left, node->val, lower) && bfs(node->right, up, node->val);
  }
};