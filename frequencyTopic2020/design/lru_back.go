package main

type BiLinkList struct {
    key int 
    val int
    next *BiLinkList
    front *BiLinkList
}

type LRUCache struct {
    head *BiLinkList
    tail *BiLinkList
    key2node map[int]*BiLinkList
    capacity int
}

func Constructor(capacity int) LRUCache {
    return LRUCache{
        key2node: make(map[int]*BiLinkList), 
        capacity: capacity,
    }
}

func (this *LRUCache) Get(key int) int {
    node, ok := this.key2node[key]
    if !ok {
        return -1;
    }
    if node == this.head {
        return this.head.val
    }
    if node == this.tail {
        this.tail = node.front
        this.tail.next = nil
        
        node.front = nil
        node.next = this.head
        this.head.front = node
        this.head = node
        return this.head.val
    }
    // in mid
    node.front.next = node.next
    node.next.front = node.front

    node.front = nil
    node.next = this.head
    this.head.front = node
    this.head = node
    return this.head.val
}

func (this *LRUCache) Put(key int, value int)  {
    node, found := this.key2node[key]
    if len(this.key2node) < this.capacity {
        if !found {
            node := &BiLinkList{key: key, val: value}
            this.key2node[key] = node
            if this.head == nil {
                this.head = node
                this.tail = node
                return;
            }
            node.next = this.head
            this.head.front = node
            this.head = node
            return
        }
    }

    // not exist and map is full
    if !found {
        // delete tail
        delete(this.key2node, this.tail.key)
        // fmt.Println("targe delete", this.tail.key)
        // delete tail
        if this.tail != nil {
            if this.tail.front == nil {
                this.head = nil
                this.tail = nil 
            } else {
                this.tail = this.tail.front
                this.tail.next = nil
            }
        }

        // create new node
        node = &BiLinkList{key: key, val: value}
        this.key2node[key] = node
    }

    node.val = value
    // found, map no need modify, move node to head
    if this.head == nil {
        this.head = node
        this.tail = node
        return
    }

    if node == this.head {
        return
    }
    // rm node from bi link list 
    if node == this.tail {
        this.tail = this.tail.front
        this.tail.next = nil
    } else {
        if node.front != nil {
            node.front.next = node.next
        }
        if node.next != nil {
            node.next = node.front
        }
    }
    
    // insert on head
    this.head.front = node
    node.next = this.head
    node.front = nil
    this.head = node
    return
}
