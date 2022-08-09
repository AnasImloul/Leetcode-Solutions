"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        q=[]
        q.append(root)
        if not root:
            return None
        while q:
            prev=None
            for i in range(len(q)):
                node=q.pop(0)
                if prev:
                    prev.next=node
                prev=node
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            prev=None
        return root
        
