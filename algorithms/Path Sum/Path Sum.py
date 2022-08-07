class Solution(object):
    def hasPathSum(self, root, targetSum):
        """
        :type root: TreeNode
        :type targetSum: int
        :rtype: bool
        """
        if not root: return False
        targetSum -= root.val
        if not root.left and not root.right:
            return not targetSum
        return self.hasPathSum(root.left, targetSum) or self.hasPathSum(root.right, targetSum)
