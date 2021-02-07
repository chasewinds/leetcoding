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
    unordered_map<int, int> inorder2idx;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            inorder2idx[inorder[i]] = i;
        }
        return buildByRange(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildByRange(vector<int>& preorder, int s, int e, vector<int>& inorder, int i, int j) {

        if (s > e /*|| s >= preorder.size() || s >= preorder.size() || i < 0 || j >= inorder.size()*/) {
            return nullptr;
        }
        int offset = inorder2idx[preorder[s]];
        TreeNode *node = new TreeNode(preorder[s]);
        // offset - i is length of left_sub_tree
        node->left = buildByRange(preorder, s + 1 , s + offset - i, inorder, i, offset - 1);
        node->right = buildByRange(preorder, s + offset - i + 1, e, inorder, offset + 1, j);

        return node;
    }
};