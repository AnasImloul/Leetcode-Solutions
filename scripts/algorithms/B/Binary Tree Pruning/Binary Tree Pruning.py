// Runtime: 35 ms (Top 80.71%) | Memory: 17.30 MB (Top 5.56%)

class Solution:
    def pruneTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if not root: return root
        root.left, root.right = self.pruneTree(root.left), self.pruneTree(root.right)
        return None if not root.val and not root.left and not root.right else root
