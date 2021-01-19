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
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == nullptr && B == nullptr) {
      return true;
    }
    if (A == nullptr || B == nullptr) {
      return false;
    }
    return isSubStructure(A->right, B) || isSubStructure(A->left, B) || isSub(A, B);
  }

  bool isSub(TreeNode *x, TreeNode *y) {
    if (y == nullptr) {
      return true;
    }
    if (x == nullptr) {
      return false;
    }

    if (x->val != y->val) {
      return false;
    }
    return isSub(x->left, y->left) && isSub(x->right, y->right);
  }
};