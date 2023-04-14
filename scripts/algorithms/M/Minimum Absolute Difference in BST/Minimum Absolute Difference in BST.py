# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        res, pre = inf, inf
        def dfs(n: Optional[TreeNode]) -> None:
            # base case
            if not n:
                return
            # recursion
            dfs(n.left)
            nonlocal res
            nonlocal pre
            res, pre = min(res, abs(pre - n.val)), n.val
            dfs(n.right)
        
        dfs(root)
        return res