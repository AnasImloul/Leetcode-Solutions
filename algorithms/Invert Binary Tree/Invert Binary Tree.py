# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        def dfs(root):
            if not root:
                return None
            root.left,root.right = dfs(root.right), dfs(root.left)
            return root
        
        return dfs(root)
		
		
2nd Solution: 

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        
        def helper(root):
            if not root:
                return None
     
            left = helper(root.left)
            right =  helper(root.right)

                
            root.left = right
            root.right = left
            return root
        
        helper(root)
        
        return root
