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
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == nullptr || q == nullptr) {
      return p == q;
    }

    vector<TreeNode *> curLevelP;
    curLevelP.push_back(p);
    vector<TreeNode *> curLevelQ;
    curLevelQ.push_back(q);
    cout << curLevelP.size() << curLevelQ.size() << endl;

    while (!curLevelP.empty() && !curLevelQ.empty()) {
//      cout << curLevelP.size() << curLevelQ.size() << endl;
      vector<TreeNode *> nextLevelP;
      vector<TreeNode *> nextLevelQ;
      while (!curLevelP.empty() && !curLevelQ.empty()) {
        cout << "in loop" << endl;
        cout << "loop: " <<  curLevelP.size() << " " <<  curLevelQ.size() << endl;
        for (auto x : curLevelP) {
          cout << "cur level p ele: " << x->val<< endl;
        }

        for (auto x : curLevelQ) {
          cout << "cur level q ele: " << x->val << endl;
        }
        auto *topP = nextLevelP.back();
        auto *topQ = nextLevelQ.back();
        cout << "after back() once" << endl;
        // deal with nullptr
        if (topP == nullptr) {
          if (topQ == nullptr) {
            nextLevelP.pop_back();
            nextLevelQ.pop_back();
            continue;
          } else {
            return false;
          }
        }

        if (topP->val != topQ->val) {
          return false;
        }
        curLevelP.pop_back();
        curLevelQ.pop_back();

        if (topP->left == nullptr && topQ->left != nullptr) {
          return false;
        } else if (topP->left != nullptr && topQ->left != nullptr) {
          nextLevelP.push_back(topP->left);
          nextLevelQ.push_back(topQ->left);
        }

        if (topP->right == nullptr && topQ->right != nullptr) {
          return false;
        } else if (topP->right != nullptr && topQ->right != nullptr) {
          nextLevelQ.push_back(topP->right);
          nextLevelQ.push_back(topQ->right);
        }
      }
      cout << "after while" << endl;
      curLevelP = nextLevelP;
      curLevelQ = nextLevelQ;
//      cout << "curlevel: " << curLevelP.size() << " curlevel q: " << curLevelQ.size() << endl;
    }
    if (!curLevelP.empty() || !curLevelQ.empty()) {
      return false;
    }

    return true;
  }
};

int main() {
  cout << "m" << endl;
  auto s = new Solution;
  TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  cout << s->isSameTree(p, q);

  return 0;
}