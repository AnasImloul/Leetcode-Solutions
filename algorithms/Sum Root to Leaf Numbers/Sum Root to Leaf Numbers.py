# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
        int_list = []
        
        def traverse(node, input_string):
            
            nonlocal int_list
            
            if not node:
                return int_list
            
            input_string = input_string + str(node.val)

            if not (node.left or node.right):
                int_list.append(int(input_string))
            
            traverse(node.left, input_string)
            traverse(node.right, input_string)
                
        traverse(root, "")
        return sum(int_list)
                
