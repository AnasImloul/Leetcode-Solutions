# Runtime: 66 ms (Top 84.95%) | Memory: 16.4 MB (Top 43.30%)
# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        res = [0]
        def tilt_helper(root,res):
            if not root:
                return 0

            left = tilt_helper(root.left,res)
            right = tilt_helper(root.right,res)

            res[0] += abs(left-right)

            return left + right + root.val

        tilt_helper(root,res)
        return res[0]