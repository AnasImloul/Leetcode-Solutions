# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        
        def valid(node,left,right):
            if not node: # checking node is none
                return True
            if not (node.val>left and node.val<right): # checking the left value is less than node and right value is greater than node
                return False
            return (valid(node.left,left,node.val) and valid(node.right,node.val,right)) # recursively calling left child and right child and returing the result  True if both are true else False
        
        return valid(root,float("-inf"),float("inf")) #calling recursive function to check