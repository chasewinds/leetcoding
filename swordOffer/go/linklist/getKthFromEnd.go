package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func getKthFromEnd(head *ListNode, k int) *ListNode {
	if head == nil {
		return nil
	}

	slow := head
	fast := head
	for i := 0; i < k && fast != nil; i++ {
		fast = fast.Next
	}

	for fast != nil {
		slow = slow.Next
		fast = fast.Next
	}

	return slow
}
