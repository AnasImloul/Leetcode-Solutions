# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        st = []

        def dfs(node):
            if node is None:
                return
            heapq.heappush(st, node.val)
            dfs(node.left)
            dfs(node.right)
        
        dfs(root)
        ans = 1e18
        first = heapq.heappop(st)
        while st:
            second = heapq.heappop(st)
            ans = min(ans, second - first)
            first = second
        return ans