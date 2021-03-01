package main

/**
 * Definition for a binary tree node.
 */

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
	if p.Val > q.Val {
		p, q = q, p
	}
	if root.Val >= p.Val && root.Val <= q.Val {
		return root
	}
	if root.Val < p.Val {
		return lowestCommonAncestor(root.Right, p, q)
	}
	return lowestCommonAncestor(root.Left, p, q)
}
