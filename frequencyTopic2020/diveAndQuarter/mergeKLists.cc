#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
// runtime 5.02% 对于某一个链表非常长的情况会空扫很多其他链表的空节点, 可用头结点的优先队列来优化
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }
    int nullCount = 0;
    ListNode *prev = new ListNode(0);
    ListNode *dummy = prev;
    vector<bool> memo = vector<bool>(lists.size(), false);
    while (nullCount < lists.size()) {
      ListNode *minNode = nullptr;
      int idx = 0;
      for (int i = 0; i < lists.size(); i++) {
        if (lists[i] == nullptr) {
          if (memo[i] == false) {
            nullCount++;
            memo[i] = true;
          }
          continue;
        }
        if (minNode == nullptr || (minNode != nullptr && lists[i]->val <
minNode->val)) { minNode = lists[i]; idx = i;
        }
      }
      if (minNode != nullptr) {
        prev->next = minNode;
        prev = minNode;
        lists[idx] = minNode->next;
      }
    }
    for (auto x : lists) {
      if (x != nullptr) {
        cout << x->val << endl;
      }
      // cout << x <<endl;
    }
    return dummy->next;
  }
};
*/



// dive and quarter, runtime 95.45% memo 5.01%
class Solution {
 public:
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.empty()) {
      return nullptr;
    }
    if (lists.size() == 1) {
      return lists[0];
    }
    if (lists.size() == 2) {
      return merge(lists[0], lists[1]);
    }
    int mid = lists.size() / 2;
    vector<ListNode*> fhalf = xslice(lists, 0, mid);
    ListNode *l1 = mergeKLists(fhalf);
    vector<ListNode*> lhalf = xslice(lists, mid + 1, lists.size() - 1);
    ListNode *l2 = mergeKLists(lhalf);
    return merge(l1, l2);
  }

  ListNode *merge(ListNode *x, ListNode *y) {
    if (x == nullptr) {
      return y;
    }
    if (y == nullptr) {
      return x;
    }
    ListNode *prev = new ListNode(0);
    ListNode *dummy = prev;
    while (x != nullptr && y != nullptr) {
      if (x->val <= y->val) {
        prev->next = x;
        prev = x;
        x = x->next;
      } else {
        prev->next = y;
        prev = y;
        y = y->next;
      }
    }
    if (x != nullptr) {
      prev->next = x;
    }
    if (y != nullptr) {
      prev->next = y;
    }
    return dummy->next;
  }
};

// 可以不借助这个辅助函数，因为他返回的是一个copy，我们其实修改下diveAndQuarter的签名，每次传入俩idx即可
vector<ListNode*> xslice(vector<ListNode*> const &v, int m, int n) {
  auto first = v.cbegin() + m;
  auto last = v.cbegin() + n + 1;

  vector<ListNode*> vec(first, last);
  return vec;
}

