#include <iostream>
#include <vector>
#include <map>

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
  vector<TreeNode*> generateTrees(int n) {
    vector<int> candidates;
    for (int i = 1; i <= n; i++) {
      candidates.push_back(i);
    }
    map<TreeNode*, int> uniqueBST;
    TreeNode* cur = new TreeNode;
    TreeNode* prev = new TreeNode(0, cur, nullptr);
    genBST(candidates, prev, cur, uniqueBST);
    vector<TreeNode*> bstList;
    for (auto it = uniqueBST.begin(); it != uniqueBST.end(); it++) {
      bstList.push_back(it->first);
    }
    return bstList;
  }

  void genBST(vector<int> candidates, TreeNode* prev, TreeNode* cur, map<TreeNode*, int>& uniqueSet) {
    if (candidates.size() == 0) {
      uniqueSet.insert(pair<TreeNode*, int>(prev->left, 0));
    }
//    if (cur->left != nullptr && cur->right != nullptr) {
//      genBST(candidates, prev, cur->left, uniqueSet);
//      genBST(candidates, prev, cur->right, uniqueSet);
//    }

    for (int x: candidates) {
      if (x < cur->val) {
        if (cur->left != nullptr) {  // if left node exist and new val can't be right node;
          continue;
        }
        TreeNode* newNode = new TreeNode(x);
        cur->left = newNode;
        vector<int> newCandidates = newVectorWithout(x, candidates);
        genBST(newCandidates, prev, cur, uniqueSet);
        cur = cur->left;
        genBST(newCandidates, prev, cur, uniqueSet);
      }
      if (x > cur->val) {
        if (cur->right != nullptr) {
          continue;
        }
        TreeNode* newNode = new TreeNode(x);
        cur->right = newNode;
        vector<int> newCandidates = newVectorWithout(x, candidates);
        genBST(newCandidates, prev, cur, uniqueSet);
        cur = cur->right;
        genBST(newCandidates, prev, cur, uniqueSet);
      }
    }
  }

  vector<int> newVectorWithout(int x, vector<int> list) {
    vector<int> res;
    for (int y : list ) {
      if (y != x) {
        res.push_back(y);
      }
    }
    return res;
  }

  void printTree(TreeNode* node) {
    if (node == nullptr) {
      cout << "null,";
      return;
    }
    cout << node->val << ",";
    printTree(node->left);
    printTree(node->right);
  }
};

int main() {
  auto s = new Solution;
  vector<TreeNode*> allTreeNodes = s->generateTrees(3);
  cout << allTreeNodes.size() << endl;
  for (TreeNode* treeHead : allTreeNodes) {
//    s->printTree(treeHead);
    cout << endl;
  }
  return 0;
}