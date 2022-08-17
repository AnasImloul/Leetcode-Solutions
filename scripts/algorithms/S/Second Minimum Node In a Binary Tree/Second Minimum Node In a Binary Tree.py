# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findSecondMinimumValue(self, root: Optional[TreeNode]) -> int:
        temp1=temp2=float(inf)
        from collections import deque
        a=deque([root])
        while a:
            node=a.popleft()
            if node.valtemp1:
                if node.val