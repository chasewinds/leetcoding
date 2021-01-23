#include <iostream>

using namespace std;

class Node {
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
                val = _val;
                next = nullptr;
                random = nullptr;
        }
};

/*
// use hash
class Solution {
        public:
                Node* copyRandomList(Node* head) {
                        if (head == nullptr) {
                                return nullptr;
                        }
                        unordered_map<Node*, Node*> copyMap;
                        Node* prev = new Node(0);
                        Node* arch = prev;
                        for (Node* cur = head; cur != nullptr; cur = cur->next) {
                                Node* ccopy = new Node(cur->val);
                                prev->next = ccopy;
                                prev = ccopy;
                                copyMap.insert({cur, ccopy});
                        }
                        auto x = arch->next;
                        for (Node* cur = head; cur != nullptr; cur = cur->next, x = x->next) {
                                if (cur->random == nullptr) {
                                        x->random = nullptr;
                                        continue;
                                }
                                auto it = copyMap.find(cur->random);
                                if (it != copyMap.end()) {
                                        x->random = it->second;
                                }
                        }
                        return arch->next;
                }
};
*/


class Solution {
        public:
		unordered_map<Node*, Node*> visited;
                Node* copyRandomList(Node* head) {
                        if (head == nullptr) {
                                return nullptr;
                        }
			if (auto it = visited.find(head); it != visited.end()) {
				return it->second;
			}
			Node *node = new Node(head->val, nullptr, nullptr);
			visited.insert({head, node});
			node->next = copyRandomList(head->next);
			node->random = copyRandomList(head->random);
                        return node;
                }
};


