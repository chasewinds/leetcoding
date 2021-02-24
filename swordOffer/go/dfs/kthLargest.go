package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func kthLargest(root *TreeNode, k int) int {
	var res []int
	preorder(root, &res)
	return res[len(res)-k]
}

func preorder(root *TreeNode, res *[]int) { // in go, must use pointer in param if inner logic need modify slice cap and len
	if root == nil {
		return
	}
	preorder(root.Left, res)
	*res = append(*res, root.Val)
	preorder(root.Right, res)
}

/*
// this is kth smallest node....
func kthLargest(root *TreeNode, k int) int {
	res := make([]int, k)
	idx := 0
	preorder(root, res, &idx)
	return res[len(res)-1]
}

func preorder(root *TreeNode, res []int, idx *int) {
	if root == nil {
		return
	}

	preorder(root.Left, res, idx)
	if *idx < len(res) {
		res[*idx] = root.Val
		*idx++
	} else {
		return
	}
	preorder(root.Right, res, idx)
}
*/
