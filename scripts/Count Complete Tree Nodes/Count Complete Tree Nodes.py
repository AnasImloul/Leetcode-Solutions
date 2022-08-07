class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        def solve(_r):
            # base cond 1 when root is None
            if _r is None: return 0
            # base cond 2 when root is the leaf node
            if _r.left is None and _r.right is None:
                return 1
            # count of nodes in left subtree
            l = solve(_r.left) 
            # count of nodes in right subtree
            r = solve(_r.right) 
            # take the sum of left subtree / right subtree + root(1)
            return l + r + 1
            
        return solve(root)