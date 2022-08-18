# Runtime: 437 ms (Top 91.25%) | Memory: 59.8 MB (Top 86.06%)

class Solution:
    def longestZigZag(self, root: Optional[TreeNode]) -> int:
        self.res = 0

        def helper(root):
            if root is None:
                return -1, -1

            leftRight = helper(root.left)[1] + 1
            rightLeft = helper(root.right)[0] + 1
            self.res = max(self.res, leftRight, rightLeft)
            return leftRight, rightLeft

        helper(root)
        return self.res