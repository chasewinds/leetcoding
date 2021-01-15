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
  int kthLargest(TreeNode* root, int k) {
    vector<int> inorderNodes;
    inorderT(inorderNodes, root);
    while (k > 1) {
      inorderNodes.pop_back();
      k--;
    }
    return inorderNodes.back();
  }

  void inorderT(vector<int>& list, TreeNode* node) {
    if (node == nullptr) {
      return;
    }

    inorderT(list, node->left);
    list.push_back(node->val);
    inorderT(list, node->right);
  }
};