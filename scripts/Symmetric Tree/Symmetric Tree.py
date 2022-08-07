class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return root is None or self.findSymmetric(root.left, root.right)
    
    def findSymmetric(self, left, right):
        if (left is None or right is None):
            return left == right
        
        if (left.val != right.val):
            return False
        
        return self.findSymmetric(left.left, right.right) and self.findSymmetric(left.right, right.left)
