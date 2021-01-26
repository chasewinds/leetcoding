func lowestCommonAncestor(root, p, q *TreeNode) *TreeNode {
     if root == nil {
         return nil
     }
    //  fmt.Println(root.Val)
     if root == p || root == q {
         return root
     }
     leftSubF := lowestCommonAncestor(root.Left, p, q)
     rightSubF := lowestCommonAncestor(root.Right, p, q)
     if leftSubF != nil && rightSubF != nil {
         return root
     }
     if leftSubF == nil {
         return rightSubF
     }
     return leftSubF
}
