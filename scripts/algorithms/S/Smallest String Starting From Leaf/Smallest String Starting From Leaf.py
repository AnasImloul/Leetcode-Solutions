# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
        
        def dfs(root, s):
            
            if not root: return
            
            if not root.left and not root.right:
                s += chr(root.val+97)
                res.append(s[-1::-1])
                return
            
            dfs(root.left, s+chr(root.val+97))
            dfs(root.right, s+chr(root.val+97))
            
            
        res = []
        dfs(root, "")
        return min(res)
		
		# An Upvote will be encouraging
