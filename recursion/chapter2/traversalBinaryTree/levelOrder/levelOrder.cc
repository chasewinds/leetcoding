#include <iostream>
#include <queue>

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
  vector<vector<int>> levelOrder(TreeNode* root) {
    if (root == nullptr) {
      return vector<vector<int>>();
    }

    queue<TreeNode *> curLayer;
    curLayer.push(root);
    vector<vector<int>> res;
    while (!curLayer.empty()) {
      queue<TreeNode *> nextLayer;
      vector<int> curRes;
      while (!curLayer.empty()) {
        TreeNode *node = curLayer.front();
        curLayer.pop();
        curRes.push_back(node->val);
        if (node->left != nullptr) {
          nextLayer.push(node->left);
        }
        if (node->right != nullptr) {
          nextLayer.push(node->right);
        }
      }
      res.push_back(curRes);
      curLayer = nextLayer;
    }

    return res;
  }
};

int main() {
  cout << "manin" << endl;
  return 0;
}