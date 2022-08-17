# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traverse(self,node,par):
        if node:
            self.parent[node.val] = par
            self.traverse(node.left,node)
            self.traverse(node.right,node)
            
    def deleteNode(self,toDelete):
                node = None
                par = self.parent[toDelete]
                if par.val == toDelete:
                    node = par
                elif par.left and par.left.val == toDelete:
                    node = par.left
                elif par.right and par.right.val == toDelete:
                    node = par.right
                if node.left:  
                    self.unique[node.left] = True
                if node.right: 
                    self.unique[node.right] = True
                    
                if node in self.unique: self.unique.pop(node)
                if node != self.parent[toDelete]:
                    if par.left == node: par.left = None
                    else: par.right = None

    
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        self.parent = {}
        self.traverse(root,root)
        self.unique = {root:True}
        for node in to_delete:
                self.deleteNode(node)
        return self.unique
