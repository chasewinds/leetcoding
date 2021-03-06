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
// if in binary search tree
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if (root == nullptr || p == nullptr || q == nullptr) {
      return nullptr;
    }

    if (root->val > p->val && root->val > q->val) {
      return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
      return lowestCommonAncestor(root->right, p, q);
    } else {
      return root;
    }
  }
};
*/


// if in binary tree
class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if (root == nullptr || root == p || root == q) {
      return root;
    }

    auto leftKid = lowestCommonAncestor(root->left, p, q);
    auto rightKid = lowestCommonAncestor(root->right, p, q);
    if (leftKid == nullptr && rightKid== nullptr) {
      return nullptr;
    } else if (leftKid == nullptr) {
      return rightKid;
    } else if (rightKid == nullptr) {
      return leftKid;
    } else {
      return root;
    }
  }
};
