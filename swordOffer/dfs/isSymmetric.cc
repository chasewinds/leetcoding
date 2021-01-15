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

/*
// create a tree copy, not perfect solution.
class Solution {
 public:
  bool isSymmetric(TreeNode *root) {

    if (root == nullptr) {
      return true;
    }
    auto mirrorTree = reverse(root);

    return equal(root, mirrorTree);
  }

  TreeNode *reverse(TreeNode *root) {
    if (root == nullptr) {
      return nullptr;
    }

    auto node = new TreeNode(root->val);
    node->left = reverse(root->right);
    node->right = reverse(root->left);
    return node;
  }

  bool equal(TreeNode *x, TreeNode *y) {
    if (x == nullptr && y == nullptr) {
      return true;
    }

    if (x != nullptr && y != nullptr) {
      if (x->val != y->val) {
        return false;
      }
      return equal(x->left, y->left) && equal(x->right, y->right);
    }
    return false;
  }
};
*/

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    return isMirror(root, root);
  }

  bool isMirror(TreeNode *x, TreeNode *y) {
    if (x == nullptr && y == nullptr) {
      return true;
    }
    if (x == nullptr || y == nullptr) {
      return false;
    }
    return x->val == y->val && isMirror(x->left, y->right) && isMirror(x->right, y->left);
  }
};
