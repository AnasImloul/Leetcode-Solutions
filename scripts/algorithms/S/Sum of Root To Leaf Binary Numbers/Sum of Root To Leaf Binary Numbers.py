# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        def path(root,p,ans):
            p.append(str(root.val))
            if root.left==None and root.right==None:
                t = int("".join(p),2)
                p.pop()
                return t+ans
            if root.left==None:
                t = path(root.right,p,ans)
                p.pop()
                return t
            if root.right==None:
                t = path(root.left,p,ans)
                p.pop()
                return t
            t = path(root.left,p,ans)+path(root.right,p,ans)
            p.pop()
            return t
        return path(root,[],0)
