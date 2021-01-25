class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 1, res);
        return res;
    }
    void dfs(TreeNode* root, int layer, vector<int>& res) {
        if (root == nullptr) {
            return ;
        }
        if (layer > res.size()) {
            res.push_back(root->val);
        }
        dfs(root->right, layer + 1, res);
        dfs(root->left, layer + 1, res);
    }
};

