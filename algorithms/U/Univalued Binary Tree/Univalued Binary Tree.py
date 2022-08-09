# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        val1 = root.val
        self.tracker = False
        def dfs(root,val1):
            if not root:
                return 
            if root.val!=val1:
                self.tracker=True
            dfs(root.left,val1)
            dfs(root.right,val1)
            return 
        dfs(root,val1)
        
        if self.tracker == False:
            return True
        return False
