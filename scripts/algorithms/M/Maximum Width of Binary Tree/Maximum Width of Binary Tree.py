# Runtime: 46 ms (Top 93.81%) | Memory: 14.7 MB (Top 75.82%)
# Definition for a binary tree node.
# class TreeNode:
# def __init__(self, val=0, left=None, right=None):
# self.val = val
# self.left = left
# self.right = right
class Solution:
    def widthOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        q = deque([(root, 0)])
        res = 0

        while q:
            res = max(res, q[-1][1] - q[0][1] + 1)
            for _ in range(len(q)):
                curr, pos = q.popleft()

                if curr.left:
                    q.append((curr.left, pos*2))
                if curr.right:
                    q.append((curr.right, pos*2 + 1))

        return res