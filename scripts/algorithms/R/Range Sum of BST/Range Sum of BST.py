// Runtime: 106 ms (Top 94.04%) | Memory: 24.40 MB (Top 92.45%)

class Solution:
    def rangeSumBST(self, root, L, R):
        if not root:
            return 0
        
        if L <= root.val <= R:
            return root.val + self.rangeSumBST(root.left, L, R) + self.rangeSumBST(root.right, L, R)
        elif root.val < L:
            return self.rangeSumBST(root.right, L, R)
        else:
            return self.rangeSumBST(root.left, L, R)



