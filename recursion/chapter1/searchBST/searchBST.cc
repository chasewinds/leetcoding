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
  TreeNode *searchBST(TreeNode *root, int val) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val == val) {
      return root;
    }
    if (val < root->val) {
      return searchBST(root->left, val);
    }
    if (val > root->val) {
      return searchBST(root->right, val);
    }
    return nullptr;
  }
};

int main() {
  cout << "hello" << endl;
  TreeNode *root = new TreeNode(
      4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));
  auto s = new Solution();
  TreeNode *matched = s->searchBST(root, 2);
  cout << "res: " << matched->val << endl;
  return 0;
}