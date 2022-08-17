class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        self.max_diff = float('-inf')
        
        def dfs(node,prev_min,prev_max):
            if not node:
                return
            dfs(node.left,min(prev_min,node.val),max(prev_max,node.val))
            dfs(node.right,min(prev_min,node.val),max(prev_max,node.val))
            self.max_diff = max(abs(node.val-prev_min),abs(node.val-prev_max),self.max_diff)
        dfs(root,root.val,root.val)
        return self.max_diff
