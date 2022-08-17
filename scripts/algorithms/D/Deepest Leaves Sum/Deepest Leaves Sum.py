# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    
    """
    THOUGHT PROCESS:
        1) find the height of the tree, this way we would know how deep we need to go.
        2) we need a counter to check how deep we are and this is not available in deepestLeavesSum so we create a new function deepestLeave.
        3) now we go in depth, if we are at bottom, we return the value, we recursively visit both left and right nodes.
        
    """
    
    def height(self, root):
        if root is None:
            return 0
        else:
            x, y = 1, 1
            if root.left:
                x = self.height(root.left)+1
            if root.right:
                y = self.height(root.right)+1
            
            return max(x, y)
            
    
    def deepestLeave(self, root, depth):
        
        if root is None:
            return 0
        
        if root.left is None and root.right is None:
            if depth == 1:
                return root.val
        
        return self.deepestLeave(root.left, depth-1) + self.deepestLeave(root.right, depth-1)
    
    def deepestLeavesSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return self.deepestLeave(root, self.height(root))
        
        
        
        
        
