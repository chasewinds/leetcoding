#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isValidBST(TreeNode* root) {
    return bfsBST(root, nullptr, nullptr);
  }

  bool bfsBST(TreeNode* root, TreeNode* max, TreeNode* min) {
    if (root == nullptr) {
      return true;
    }
//    cout << "root val: " << root->val << " high: " << high << " low: " << low << endl;
    if (max != nullptr) {
      if (root->val >= max->val) {
        return false;
      }
    }
    if (min != nullptr) {
      if (root->val <= min->val) {
        return false;
      }
    }
    return bfsBST(root->left, root, min) && bfsBST(root->right, max, root);
  }
};

int main() {
//  TreeNode* case1 = new TreeNode(5, new TreeNode(1), new TreeNode(4, new TreeNode(3), new TreeNode(6)));
//  TreeNode* case2 = new TreeNode(INT_MIN, nullptr, new TreeNode(INT_MAX));
  TreeNode* case3 = new TreeNode(1, nullptr, new TreeNode(1));

  auto s = new Solution;
  cout << s->isValidBST(case3) << endl;
  return 0;
}