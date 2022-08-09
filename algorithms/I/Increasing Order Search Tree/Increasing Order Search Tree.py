# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        def inorder(root,a):
            if root:
                inorder(root.left,a)
                a.append(root.val)
                inorder(root.right,a)
        
        a=[]
        inorder(root,a)
        p1=TreeNode()
        tmp=p1
        for i in range(len(a)):
            if i==len(a)-1:
                p1.val=a[i]
            else:
                p1.val=a[i]
                p1.right=TreeNode()
                p1=p1.right
        return tmp
