#include <iostream>
#include <unordered_map>

using namespace std;

// runtime beat 99.83%, memo beat 97.42%
struct LRUNode {
  int key;
  int value;
  LRUNode *next;
  LRUNode *ahead;
  LRUNode(int key, int value)
      : key(key), value(value), next(nullptr), ahead(nullptr) {}
  LRUNode(int key, int value, LRUNode *next, LRUNode *ahead)
      : key(key), value(value), next(next), ahead(ahead) {}
};

class LRUCache {
 public:
  LRUNode *head;
  LRUNode *tail;
  unordered_map<int, LRUNode *> keyToNode;
  int cap;
  LRUCache(int capacity) {
    cap = capacity;
    head = nullptr;
    tail = nullptr;
  }

  int get(int key) {
    auto it = keyToNode.find(key);
    if (it == keyToNode.end()) {
      return -1;
    }
    auto nodeGoAhead = it->second;
    if (nodeGoAhead == head) {
      return nodeGoAhead->value;
    }
    if (nodeGoAhead == tail) {
      // cout << "in get: " << nodeGoAhead->value << "match tail" << endl;
      tail = nodeGoAhead->ahead;
    }
    if (nodeGoAhead->ahead != nullptr) {
      nodeGoAhead->ahead->next = nodeGoAhead->next;
    }
    if (nodeGoAhead->next != nullptr) {
      nodeGoAhead->next->ahead = nodeGoAhead->ahead;
    }
    nodeGoAhead->next = head;
    head->ahead = nodeGoAhead;
    nodeGoAhead->ahead = nullptr;
    head = nodeGoAhead;
    return head->value;
  }

  void put(int key, int value) {
    if (auto it = keyToNode.find(key); it != keyToNode.end()) {
      auto nodeGoingAhead = it->second;
      if (nodeGoingAhead == head) {
        head->value = value;
        return;
      }
      if (nodeGoingAhead == tail) {
        tail = nodeGoingAhead->ahead;
      }
      nodeGoingAhead->value = value;
      if (nodeGoingAhead->ahead != nullptr) {
        nodeGoingAhead->ahead->next = nodeGoingAhead->next;
      }
      if (nodeGoingAhead->next != nullptr) {
        nodeGoingAhead->next->ahead = nodeGoingAhead->ahead;
      }

      nodeGoingAhead->ahead = nullptr;
      nodeGoingAhead->next = head;
      head->ahead = nodeGoingAhead;  // head must not be nullptr
      head = nodeGoingAhead;
      return;
    }

    // delete one to satisfy normal insert
    if (keyToNode.size() == cap) {
      auto it = keyToNode.find(tail->key);
      auto nodeGoingToDie = it->second;
      if (nodeGoingToDie->ahead != nullptr) {
        nodeGoingToDie->ahead->next = nodeGoingToDie->next;
      }
      tail = tail->ahead;
      keyToNode.erase(nodeGoingToDie->key);
    }

    LRUNode *node = new LRUNode(key, value, head, nullptr);
    if (head != nullptr) {
      head->ahead = node;
    } else {
      tail = node;
    }
    head = node;
    keyToNode.insert({key, node});
    return;
  }
};
