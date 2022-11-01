# Runtime: 197 ms (Top 13.70%) | Memory: 26.4 MB (Top 30.94%)
class Solution:
    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        # escape condition
        if (not root) or (root == p) or (root == q):
            return root
        # search left and right subtree
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if left and right:
            # both found, root is the LCA
            return root
        return left or right