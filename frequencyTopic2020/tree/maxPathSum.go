package main

var res int;
func maxPathSum(root *TreeNode) int {
    if root == nil {
        return 0
    }
    res = root.Val
    maxValue(root)
    return res;
}

func maxValue(root *TreeNode) int {
    if root == nil {
        return 0;
    }
    leftMax := max(maxValue(root.Left), 0)
    rightMax := max(maxValue(root.Right), 0)
    sum := leftMax + rightMax + root.Val;
    res = max(res, sum)
    return max(leftMax, rightMax) + root.Val
}

func max(x, y int) int {
    if (x >= y) {
        return x
    }
    return y
}