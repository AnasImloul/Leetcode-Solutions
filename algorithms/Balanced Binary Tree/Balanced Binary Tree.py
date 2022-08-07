# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isBalanced(self, root: TreeNode) -> bool:

        # Initialize the result to True
        res = True

        # DFS through the tree
        def dfs(node, i):
            nonlocal res

            # If there isn't a node, return previous depth
            if not node:
                return i - 1

            # Check depths of the left and right subtrees
            left, right = dfs(node.left, i + 1), dfs(node.right, i + 1)

            # If they are more than 1 difference, save False to the result
            if abs(right - left) > 1:
                res = False

            # Return the max depth of both subtrees
            return max(left, right)

        dfs(root, 0)

        return res
