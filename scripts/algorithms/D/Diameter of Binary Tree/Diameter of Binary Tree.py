# Runtime: 95 ms (Top 16.95%) | Memory: 16.5 MB (Top 10.21%)
class Solution:
    """
    Top Down recursion approach: it is sub optimal
    """
    def __init__(self):
        self.max_diameter = 0
    def diameter(self, root):
        if root is None:
            return 0
        return self.max_depth(root.left) + self.max_depth(root.right)

    def max_depth(self, root):
        if root is None:
            return 0
        return 1 + max(self.max_depth(root.left), self.max_depth(root.right))

    def func(self, root):
        if root is not None:
            diameter = self.diameter(root)
            if self.max_diameter < diameter:
                self.max_diameter = diameter
            self.diameterOfBinaryTree(root.left)
            self.diameterOfBinaryTree(root.right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.func(root)
        return self.max_diameter

    """
    Better Approach: I can try to approach this problem using bottom up recursion
    """
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.diameter = 0
        def fun(root):
            if root is None:
                return 0
            left = fun(root.left)
            right = fun(root.right)
            if left + right > self.diameter:
                self.diameter = left + right
            return max(left, right) + 1
        fun(root)
        return self.diameter