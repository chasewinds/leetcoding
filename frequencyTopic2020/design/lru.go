package main

type LRUCache struct {
    head, tail *DLinkList
    capacity, size int
    key2node map[int]*DLinkList
}

type DLinkList struct {
    key, val int
    next, front *DLinkList
}

func Constructor(capacity int) LRUCache {
    l := LRUCache {
        head: &DLinkList{key: 0, val: 0},
        tail: &DLinkList{key: 0, val: 0},
        capacity: capacity,
        key2node : make(map[int]*DLinkList),
    }
    l.head.next = l.tail
    l.tail.front = l.head
    return l
}

func (this *LRUCache) Get(key int) int {
    node, found := this.key2node[key]
    if !found {
        return -1
    }
    this.moveToHead(node)
    return node.val
}

func (this *LRUCache) Put(key, value int) {
    /*
    node, found := this.key2node[key]
    if found {
        if value != node.val {
            node.val = value
        }
        this.moveToHead(node)
        return
    }

    // new node came
    if len(this.key2node) >= this.capacity {
        tailKey := this.removeTail()
        delete(this.key2node, tailKey)
    }
    node = &DLinkList{key: key, val: value}
    this.key2node[key] = node
    this.insertToHead(node)
    */
    node, found := this.key2node[key]
    if found {
        // node.val = value
        this.key2node[key].val = value
        this.moveToHead(node)
        return
    }
    node = &DLinkList{key: key, val: value}
    this.key2node[key] = node
    this.insertToHead(node)
    this.size++
    if (this.size > this.capacity) {
        tailKey := this.removeTail()
        delete(this.key2node, tailKey)
        this.size--
    }
}

func (this *LRUCache) moveToHead(node *DLinkList) {
    this.removeNode(node)
    this.insertToHead(node)
}

func (this *LRUCache) insertToHead(node *DLinkList) {
    node.front = this.head
    node.next = this.head.next
    this.head.next.front = node
    this.head.next = node
}

func (this *LRUCache) removeNode(node *DLinkList) {
    node.front.next = node.next
    node.next.front = node.front
}

func (this *LRUCache) removeTail() int {
    node := this.tail.front
    val := node.val
    this.removeNode(node)
    return val
}
