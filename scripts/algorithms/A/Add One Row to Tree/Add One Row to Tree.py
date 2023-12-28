// Runtime: 77 ms (Top 6.3%) | Memory: 18.50 MB (Top 98.9%)

class Solution:
    def addOneRow(self, root: TreeNode, v: int, d: int) -> TreeNode:
        if d == 1: return TreeNode(v, root, None)
        elif d == 2:
            root.left = TreeNode(v, root.left, None)
            root.right = TreeNode(v, None, root.right)
        else:
            if root.left: self.addOneRow(root.left, v, d-1)
            if root.right: self.addOneRow(root.right, v, d-1)
        return root
