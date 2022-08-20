# Runtime: 86 ms (Top 42.71%) | Memory: 18.1 MB (Top 15.27%)

# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        n=0
        stack=[] # to store the elements
        cur=root # pointer to iterate
        while cur or stack:
            while cur: # used to find the left most element
                stack.append(cur)
                cur=cur.left
            cur=stack.pop() # pop the most recent element which will be the least value at that moment
            n+=1
            if n==k:
                return cur.val
            cur=cur.right