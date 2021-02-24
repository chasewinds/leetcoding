package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func levelOrder(root *TreeNode) [][]int {

	if root == nil {
		return nil
	}

	var res [][]int
	q := []*TreeNode{root}
	for len(q) > 0 {
		layerSize := len(q)
		var layer []int
		for i := 0; i < layerSize; i++ {
			top := q[0]
			q = q[1:]
			if top != nil {
				layer = append(layer, top.Val)
				q = append(q, top.Left)
				q = append(q, top.Right)
			}
		}
		if len(layer) != 0 {
			res = append(res, layer)
		}
	}

	return res
}
