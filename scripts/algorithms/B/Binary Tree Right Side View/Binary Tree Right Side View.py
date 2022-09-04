# Runtime: 54 ms (Top 45.43%) | Memory: 13.9 MB (Top 70.59%)
# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:

        def dfs(root, d):

            if not root: return

            if self.maxi < d:
                self.res.append(root.val)
                self.maxi = d

            dfs(root.right, d+1)
            dfs(root.left, d+1)

        self.res, self.maxi = [], 0
        dfs(root, 1)
        return self.res

        # An Upvote will be encouraging
