# Runtime: 98 ms (Top 35.75%) | Memory: 14.7 MB (Top 20.30%)
class Solution:
    def evaluateTree(self, root: Optional[TreeNode]) -> bool:
        def recur(node):
            if not node.left and not node.right: #leaf node
                return True if node.val == 1 else False
            left = recur(node.left)
            right = recur(node.right)
            if node.val == 2: #if node is or
                return left or right
            if node.val == 3: #if node is and
                return left and right
        return recur(root)