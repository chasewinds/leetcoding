package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func mirrorTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}

	l := mirrorTree(root.Right)
	r := mirrorTree(root.Left)
	root.Left = l
	root.Right = r
	return root
}
