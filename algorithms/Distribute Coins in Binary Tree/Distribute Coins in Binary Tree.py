# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        
        def dfs(root):
            if not root:
                return 0,0
            
            net_left,left_walk = dfs(root.left)
            net_right,right_walk = dfs(root.right)
            
			# if any node has extra or deficiency in both cases there has to be a walk of abs(extra) or abs(deficiency)
			
            return net_left+net_right+(root.val-1), left_walk+right_walk+abs(net_left)+abs(net_right)
        return dfs(root)[1]
