# Runtime: 556 ms (Top 18.24%) | Memory: 15.4 MB (Top 89.19%)
class node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

class Solution:
    def BST(self, root, cur):
        if cur.val < root.val:
            if root.left == None:
                root.left = cur
                return
            else:
                self.BST(root.left, cur)
        elif cur.val > root.val:
            if root.right == None:
                root.right = cur
                return
            else:
                self.BST(root.right, cur)

    def solve(self, root):
        if root.left == None and root.right == None:
            return 1
        left = 0 ; right = 0
        if root.left is not None:
            left = self.solve(root.left)
        if root.right is not None:
            right = self.solve(root.right)
        self.total *= math.comb(left + right, left)
        return left + right + 1

    def numOfWays(self, nums: List[int]) -> int:
        import math
        self.total = 1
        root = node(nums[0])
        for i in range(1, len(nums)):
            self.BST(root, node(nums[i]))
        self.solve(root)
        return (self.total - 1) % (int(1e9) + 7)