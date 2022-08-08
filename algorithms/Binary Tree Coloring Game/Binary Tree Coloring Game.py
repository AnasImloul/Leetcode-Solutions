# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findParent(self,node,par = None):
        if node:
            self.parent[node.val] = par
            self.findParent(node.left,node)
            self.findParent(node.right,node)
    
    def traverse(self,node,done):
        if node:
            if node in done: return 0
            done[node] = True
            a = self.traverse(self.parent[node.val],done)
            b = self.traverse(node.left,done)
            c = self.traverse(node.right,done)
            return a + b + c + 1
        return 0
    
    def btreeGameWinningMove(self, root: Optional[TreeNode], n: int, x: int) -> bool:
        self.parent = {}
        self.findParent(root)
        parent = self.parent[x]
        node = root if root.val == x else parent.left if parent and parent.left and parent.left.val == x else parent.right
        up = self.traverse(parent,{node:True})
        left = self.traverse(node.left,{node:True})
        right = self.traverse(node.right,{node:True})
        return (up > left + right) or (left > up + right) or (right > up + left)
