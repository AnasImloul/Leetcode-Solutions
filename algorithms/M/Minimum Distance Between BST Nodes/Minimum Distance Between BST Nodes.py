# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        temp1=float(inf)
        from collections import deque
        a=deque([root])
        b=[]
        while a:
            node=a.popleft()
            b.append(node.val)
            if node.left:
                a.append(node.left)
            if node.right:
                a.append(node.right)
        b.sort()
        for i in range(0,len(b)-1):
            if b[i+1]-b[i]