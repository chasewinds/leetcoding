func diameterOfBinaryTree(root *TreeNode) int {
    var res = 0
    var dfs func(root *TreeNode) int 
    dfs = func (root *TreeNode) int {
        if root == nil {
            return 0
        }
        left := dfs(root.Left)
        right := dfs(root.Right)
        // fmt.Println(root.Val, " ", res, " ", left, " ", right, " ", left + right)
        cur := left + right
        res = max(res, cur)
        return max(left, right) + 1
    }
    dfs(root)
    return res
}

func max(x, y int) int {
    if (x >= y) {
        return x
    }
    return y
}
