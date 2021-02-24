package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func deleteNode(head *ListNode, val int) *ListNode {
	if head == nil {
		return nil
	}
	if head.Val == val {
		return head.Next
	}

	prev := &ListNode{0, head}
	for cur := head; cur != nil; cur = cur.Next {
		if cur.Val == val {
			prev.Next = cur.Next
		}
		prev = cur
	}

	return head
}
