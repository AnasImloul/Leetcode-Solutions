"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        ans=[]
        def post(root):
            nonlocal ans
            if not root:
                return
            for i in root.children:
                post(i)
            ans.append(root.val)
        post(root)
        return ans
