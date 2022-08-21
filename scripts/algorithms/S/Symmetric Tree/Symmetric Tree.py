# Runtime: 50 ms (Top 60.40%) | Memory: 13.9 MB (Top 94.25%)

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return root is None or self.findSymmetric(root.left, root.right)

    def findSymmetric(self, left, right):
        if (left is None or right is None):
            return left == right

        if (left.val != right.val):
            return False

        return self.findSymmetric(left.left, right.right) and self.findSymmetric(left.right, right.left)