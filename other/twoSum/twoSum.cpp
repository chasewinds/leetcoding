#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        ListNode* head = new ListNode(0, nullptr);
        ListNode* prev = head;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum >= 10) {
                head->next = new ListNode(sum % 10, nullptr);
                sum = sum / 10;
            } else {
                head->next = new ListNode(sum, nullptr);
                sum = 0;
            }
            head = head->next;
        }
        if (sum != 0) {
            head->next = new ListNode(sum, nullptr);
        }
        return prev->next;
    }
};

int main() {
    auto s = new Solution;
    auto l1 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, nullptr)))))));
    auto l2 = new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, nullptr))));

    for (ListNode* head = s->addTwoNumbers(l1, l2); head != nullptr; head = head->next) {
        cout << head->val << endl;
    }
    return 0;
}
