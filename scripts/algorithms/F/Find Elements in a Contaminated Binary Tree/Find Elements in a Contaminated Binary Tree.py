# Runtime: 227 ms (Top 13.41%) | Memory: 18.1 MB (Top 62.12%)
# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class FindElements:

    def __init__(self, root: Optional[TreeNode]):
        def recoverTree(root):
            if not root:
                return None
            self.vals.add(root.val)
            if root.left:
                root.left.val = 2 * root.val + 1
                recoverTree(root.left)
            if root.right:
                root.right.val = 2 * root.val + 2
                recoverTree(root.right)
        self.vals = set()
        root.val = 0
        recoverTree(root)

    def find(self, target: int) -> bool:
        return target in self.vals

# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)