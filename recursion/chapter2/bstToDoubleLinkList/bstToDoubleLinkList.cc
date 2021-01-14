#include <iostream>
#include <vector>

using namespace std;

class Node {
 public:
  int val;
  Node *left;
  Node *right;

  Node() {}

  Node(int _val) {
    val = _val;
    left = nullptr;
    right = nullptr;
  }

  Node(int _val, Node* _left, Node* _right) {
    val = _val;
    left = _left;
    right = _right;
  }
};

/*
class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    vector<int> sortedList;
    dfsOrderList(sortedList, root);
    Node *prev = new Node;
    Node *head = new Node;
    Node *tail = new Node;
    for (int i = 0; i < sortedList.size(); i++) {
      Node *node = new Node(sortedList[i]);
      prev->right = node;
      prev = node;
      if (i == sortedList.size() - 1) {
        tail = node;
      }
      if (i == 0) {
        head = node;
      }
    }
//    cout << "head: " << head->val << " head.left: " << head->left << " head.right: " << head->right << endl;
//    cout << "tail: " << tail->val << " tail.left: " << tail->left << " tail.right: " << tail->right << endl;

    tail->right = head;
    head->left = tail;

    Node *node = head;
    Node *pprev = head->left;
    do {
      pprev = node;
      node = node->right;
      node->left = pprev;
    } while (node != head);
    return head;
  }

  void dfsOrderList(vector<int>& res, Node* root) {
    if (root == nullptr) {
      return;
    }

    dfsOrderList(res, root->left);
    res.push_back(root->val);
    dfsOrderList(res, root->right);
  }
};
 */

class Solution {
 public:
  // must use class level global var, can't use rec func param, cause back track may suffer unexpected things
  Node *first;
  Node *prev;

  Node* treeToDoublyList(Node* root) {

    if (root == nullptr) {
      return nullptr;
    }

//    Node *first = nullptr;
//    Node *prev = nullptr;
    inorderTraversalTree(root);
    first->left = prev;
    prev->right = first;

    return first;
  }

  void inorderTraversalTree(Node* cur) {

    if (cur == nullptr) {
      return;
    }

    inorderTraversalTree(cur->left);

    // in mid, do
    if (prev != nullptr) {
      prev->right = cur;
      cur->left = prev;
    } else {
      first = cur;
    }
    prev = cur;

    inorderTraversalTree(cur->right);
  }
};


int main() {
  auto s = new Solution;
  Node *root = new Node(4, new Node(2, new Node(1), new Node(3)), new Node(5));
  Node *res = s->treeToDoublyList(root);
  for (Node *head = res; head != nullptr; head = head->left) {
    cout << head->val << endl;
  }
  return 0;
}