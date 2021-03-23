package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    prev := &ListNode{}
    dummy := prev
    var up int

    for l1 != nil || l2 != nil || up != 0 {
        sum := up
        if l1 != nil {
            sum += l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            sum += l2.Val
            l2 = l2.Next
        }
        if sum >= 10 {
            up = sum / 10
            sum %= 10
        } else {
            up = 0
        }
        node := &ListNode{Val: sum}
        prev.Next = node
        prev = prev.Next
    }

    return dummy.Next
}
