class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        hashMap = {}
        
        def helper(root: Optional[TreeNode]) -> int:
            if not root:
                return 0
            if root in hashMap:
                return hashMap[root]
            ansOption1 = root.val
            if root.left is not None:
                ansOption1 += (helper(root.left.left) + helper(root.left.right))
            if root.right is not None:
                ansOption1 += (helper(root.right.left) + helper(root.right.right))
            ansOption2 = helper(root.left) + helper(root.right)
            ansFinal = max(ansOption1, ansOption2)
            hashMap[root] = ansFinal
            return ansFinal
        
        return helper(root)
                
