class Solution:
    def rangeSumBST(self, root: Optional[TreeNode], low: int, high: int) -> int:
    
        res = 0
        
        def dfs(node):
            nonlocal res
            
            if not node:
                return
            
            if node.val >= low and node.val <= high:
                
                res += node.val
                
            dfs(node.left)
            dfs(node.right)
            
        dfs(root)
        
        return res
