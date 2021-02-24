package main

// Definition for singly-linked list.
type ListNode struct {
	Val  int
	Next *ListNode
}

func reversePrint(head *ListNode) []int {
	if head == nil {
		return nil
	}

	var prev *ListNode
	cur := head
	for cur != nil {
		next := cur.Next
		cur.Next = prev
		prev = cur
		cur = next
	}

	var res []int
	for cur := prev; cur != nil; cur = cur.Next {
		res = append(res, cur.Val)
	}

	return res
}
