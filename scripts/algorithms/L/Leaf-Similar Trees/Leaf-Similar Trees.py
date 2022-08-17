# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        tree=[]
        def inorder(root):
            nonlocal tree
            if root is None:
                return
            if root.left is None and root.right is None:
                tree.append(root.val)
            
            inorder(root.left)
            inorder(root.right)
        
        inorder(root1)
        inorder(root2)
        tree1=tree[:len(tree)//2]
        tree2=tree[len(tree)//2:]
        if tree1==tree2:
            return True
        else:
            return False