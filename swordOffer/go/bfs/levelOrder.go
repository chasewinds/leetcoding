package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) []int {
	if root == nil {
		return nil
	}

	var res []int
	stk := []*TreeNode{root}
	for len(stk) != 0 {
		layerSize := len(stk)
		for i := 0; i < layerSize; i++ {
			top := stk[0]
			stk = stk[1:]
			if top != nil {
				res = append(res, top.Val)
				stk = append(stk, top.Left)
				stk = append(stk, top.Right)
			}
		}
	}

	return res
}
