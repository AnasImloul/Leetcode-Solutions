# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def balanceBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        arr = []
        self.flatTree(root, arr)
        return self.createTree(arr, 0, len(arr))
    
    def flatTree(self, root, arr):
        if not root:
            return
        self.flatTree(root.left, arr)
        arr.append(root)
        self.flatTree(root.right, arr)
    
    def createTree(self, arr, start, length):
        if length == 0:
            return None
        root = arr[start + length / 2]
        root.left = self.createTree(arr, start, length / 2)
        root.right = self.createTree(arr, start + length / 2 + 1, length - length / 2 - 1)
        return root
