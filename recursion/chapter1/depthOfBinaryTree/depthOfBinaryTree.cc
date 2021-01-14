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
  int maxDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return maxDepthTailRec(root, 0);
  }
  int maxDepthTailRec(TreeNode *node, int depth) {
    if (node == nullptr) {
      return depth;
    }
    depth++;
    return max(maxDepthTailRec(node->right, depth), maxDepthTailRec(node->left, depth));
  }
};

int main() {
  auto s = new Solution;
//  TreeNode *tree = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
//  TreeNode *tree = new TreeNode(1, nullptr, new TreeNode(2));
  TreeNode *tree = new TreeNode;
  cout << s->maxDepth(tree) << endl;
  return 0;
}