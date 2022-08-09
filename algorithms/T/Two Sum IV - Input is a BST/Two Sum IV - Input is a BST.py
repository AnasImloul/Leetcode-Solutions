# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        def inorder(root,l):
            if root:
                inorder(root.left,l)
                l.append(root.val)
                inorder(root.right,l)
        l = []
        inorder(root,l)
        left,right=0,len(l)-1
        while left!=right:
            sum = l[left] + l[right]
            if sum > k :
                right -=1
            elif sum <k:
                left +=1
            else:
                return 1
        return 0
