package main

type LinkNode struct {
    Val int
    Next *LinkNode
}

func reverseKGroup(head *ListNode, k int) *ListNode {
    if k == 1 {
        return head
    }

    prev := &ListNode{Val: 0, Next: head}
    dummy := prev
    l := head
    for l != nil {
        r := l
        // go
        for i := 0; i < k - 1; i++ {
            r = r.Next
            if r == nil {
                return dummy.Next
            }
        }

        next := r.Next
        // reverse
        l, r = reverseInterval(l, r)

        // link
        prev.Next = l
        r.Next = next

        // move
        prev = r
        l = next
    }

    return dummy.Next
}

func reverseInterval(head, tail *ListNode) (*ListNode, *ListNode) {
    pre := tail.Next
    for cur := head; pre != tail; {
        next := cur.Next
        cur.Next = pre
        pre = cur
        cur = next
    }
    return tail, head
}
