class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        if root.left is None:
            return self.minDepth(root.right) + 1
        if root.right is None:
            return self.minDepth(root.left) + 1
        
        l_ht = self.minDepth(root.left)
        r_ht = self.minDepth(root.right)
        
        return min(l_ht, r_ht) + 1
