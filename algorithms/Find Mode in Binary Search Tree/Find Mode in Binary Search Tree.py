class Solution:
    def __init__(self):
        self.d = {}
        self.m = 1
        self.ans = []
        
    def dfs(self, x):
        if not x:
            return
        if x.val not in self.d:
            self.d[x.val] = 1    
        else:
            self.d[x.val] += 1
            self.m = max(self.m, self.d[x.val])
            
        self.dfs(x.left)
        self.dfs(x.right)
    
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        self.dfs(root)
        for x in self.d:
            if self.d[x] == self.m:
                self.ans.append(x)
        return self.ans
