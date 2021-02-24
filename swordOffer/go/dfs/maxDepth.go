package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return walk(root, 0)
}

func walk(root *TreeNode, depth int) int {
	if root == nil {
		return depth
	}
	return max(walk(root.Left, depth+1), walk(root.Right, depth+1))
}

func max(x, y int) int {
	if x > y {
		return x
	}
	return y
}
