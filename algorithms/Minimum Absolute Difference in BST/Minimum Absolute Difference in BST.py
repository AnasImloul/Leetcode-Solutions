# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference1(self, root: Optional[TreeNode]) -> int:
        
        self.res = float('inf')
        self.prev = float('inf')
        def inorder(root):
            if root==None:
                return
            inorder(root.left)
            self.res=min(self.res,abs(self.prev-root.val))
            self.prev=root.val
            inorder(root.right)
            
        inorder(root)
        return self.res
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.res=float("inf")
        self.prev=float("inf")
        def inorder(root):
            if root==None:
                return 
            inorder(root.left)
            self.res=min(self.res,abs(self.prev-root.val))
            self.prev=root.val
            inorder(root.right)
        inorder(root)
        return self.res

