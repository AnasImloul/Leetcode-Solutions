# Runtime: 87 ms (Top 85.77%) | Memory: 16.7 MB (Top 24.56%)
# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        def search(root):
            if not root:return None
            if root.val==val:
                return root
            elif root.val<val:
                ans=search(root.right)
                if ans:
                    return ans
                return None
            else:
                ans=search(root.left)
                if ans:
                    return ans
                return None
        return search(root)