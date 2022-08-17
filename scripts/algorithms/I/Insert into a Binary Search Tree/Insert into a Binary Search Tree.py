# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root: return TreeNode(val)
        def search(root):
            if val>root.val:
                if root.right:
                    search(root.right)
                else:
                    root.right=TreeNode(val)
                    return 
            else:
                if root.left:
                    search(root.left)
                else:
                    root.left=TreeNode(val)
                    return
        search(root)
        return root
