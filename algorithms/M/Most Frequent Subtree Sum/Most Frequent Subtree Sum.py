# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findFrequentTreeSum(self, root: Optional[TreeNode]) -> List[int]:
        def dfs(root):
            
            if not root: return 0
            
            l = dfs(root.left)
            r = dfs(root.right)
            res = root.val + l + r
            
            d[res] += 1
            return res
        
        d = collections.Counter()
        dfs(root)
        maxi = max(d.values())
        return [i for i in d if d[i] == maxi]
        
		# An Upvote will be encouraging
        
        
