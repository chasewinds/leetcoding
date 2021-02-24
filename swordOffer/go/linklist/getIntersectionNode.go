package main

type ListNode struct {
	Val  int
	Next *ListNode
}

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}

	a := headA
	b := headB
	var ca, cb bool // no need, if no intersaction, they will meet at nil
	for a != b {
		if a == nil || b == nil {
			return nil
		}
		a = a.Next
		if !ca && a == nil {
			a = headB
			ca = true
		}

		b = b.Next
		if !cb && b == nil {
			b = headA
			cb = true
		}
	}

	return a
}

/*
func getIntersectionNode(headA, headB *ListNode) *ListNode {
	if headA == nil || headB == nil {
		return nil
	}

	a := headA
	b := headB
	for a != b {
        if a == nil {
            a = headB
        } else {
            a = a.Next
        }
        if b == nil {
            b = headA
        } else {
            b = b.Next
        }
	}

	return a
}
*/
