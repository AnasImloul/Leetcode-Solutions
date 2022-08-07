# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        
        res = root.val
        stack = [(0, root)]
        prev_d = 0
        
        while stack:
            
            curr_d, curr_v = stack.pop(0)
            
            if curr_v.left:
                stack.append((curr_d+1, curr_v.left))
                if prev_d != curr_d + 1:
                    res = curr_v.left.val
                    prev_d = curr_d+1
            
            if curr_v.right:
                stack.append((curr_d+1, curr_v.right))
                if prev_d != curr_d + 1:
                    res = curr_v.right.val
                    prev_d = curr_d+1
        
        return res
		
		# An Upvote will be encouraging
