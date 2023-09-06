# Runtime: 36 ms (Top 83.6%) | Memory: 16.39 MB (Top 54.5%)

class Solution:
    def bstToGst(self, root):
        self.total = 0
        def dfs(n):
            if n:
                dfs(n.right)
                self.total +=  n.val
                n.val       =  self.total
                dfs(n.left)
        dfs(root)
        return root