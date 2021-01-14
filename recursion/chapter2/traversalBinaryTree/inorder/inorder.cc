#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

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

  vector<int> inorderTraversal(TreeNode *root) {
    TreeNode *x = root;
    vector<int> res;
    TreeNode *predecessor = nullptr;
    while (x != nullptr) {
      if (x->left == nullptr) {
        res.push_back(x->val);
        x = x->right;
        continue;
      }

      // key point! predecessor is the right more left sub tree,
      // to find it, x.left.right is not enough, must use while loop!
      predecessor = x->left;
      while (predecessor->right != nullptr && predecessor->right != x) {
        predecessor = predecessor->right;
      }

      if (predecessor->right == nullptr) {
        predecessor->right = x;
        x = x->left;
        continue;
      }
      predecessor->right = nullptr;
      res.push_back(x->val);
      x = x->right;
    }
    return res;
  }

//  vector<int> inorderTraversal(TreeNode *root) {
//    if (root == nullptr) {
//      return vector<int>{};
//    }
//
//    vector<int> res;
//    stack<TreeNode*> tstack;
////    tstack.push_back(root);
//
//    while (root != nullptr || !tstack.empty()) {
//      cout << "loop" << endl;
//      while (root != nullptr) {
//        tstack.push(root);
//        root = root->left;
//      }
//      root = tstack.top();
//      tstack.pop();
//      res.push_back(root->val);
//      root = root->right;
//    }
//    return res;
//  }

//    vector<int> inorderTraversal(TreeNode* root) {
//    vector<int> res;
//    dfsTree(res, root);
//    return res;
//  }
//
//  void dfsTree(vector<int>& res, TreeNode* cur) {
//    if (cur == nullptr) {
//      return;
//    }
//
//    dfsTree(res, cur->left);
//    res.push_back(cur->val);
//    dfsTree(res, cur->right);
//  }
};

int main() {
  auto s = new Solution;
  TreeNode *root = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
  vector<int> res = s->inorderTraversal(root);
  for (auto x : res) {
    cout << x;
  }
  return 0;
}