def is_leaf(x):
    return x.left is None and x.right is None

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left and is_leaf(root.left):
            left = root.left.val
        else:
            left = self.sumOfLeftLeaves(root.left)
        return left + self.sumOfLeftLeaves(root.right)
