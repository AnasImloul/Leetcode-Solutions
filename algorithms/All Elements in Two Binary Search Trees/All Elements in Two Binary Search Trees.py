
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        
        
        l1,l2=[],[]
        def preorder(root,l):
            if root is None:
                return 
            preorder(root.left,l)
            l.append(root.val)
            preorder(root.right,l)
        preorder(root1,l1)
        preorder(root2,l2)
        return sorted(l1+l2)
