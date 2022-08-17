class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if subRoot == None:
            return True
        if root == None:
            return False
        
        sameTree = self.isSameTree(root, subRoot)
        subTreeOnLeft = self.isSubtree(root.left, subRoot)
        subTreeOnRight = self.isSubtree(root.right, subRoot)
        
        return subTreeOnLeft or subTreeOnRight or sameTree
        
    def isSameTree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if (root == None and subRoot == None):
            return True
        
        if (root == None or subRoot == None):
            return False
        
        if (root.val != subRoot.val):
            return False
        
        return self.isSameTree(root.left, subRoot.left) and self.isSameTree(root.right, subRoot.right)
