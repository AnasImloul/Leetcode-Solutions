# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    
        
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        
        ret = []
        next_levels = [[root]]
        
        for level in next_levels:
            curr_lv = []
            next_lv = []
            for node in level:
                if not node: 
                    continue
                curr_lv.append(node.val)
                next_lv.append(node.left)
                next_lv.append(node.right)
            
            if curr_lv: 
                ret.append(curr_lv)
            if next_lv: 
                next_levels.append(next_lv)
        
        return ret
