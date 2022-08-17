class Solution:
    def longestCycle(self, edges: List[int]) -> int:
        preorder = [-1 for _ in range(len(edges))]
        self.ans = -1
        self.pre = 0
        
        def dfs(self, i: int, st: int) -> None:
            preorder[i] = self.pre
            self.pre += 1
            
            if edges[i] == -1:
                return
            elif preorder[edges[i]] == -1:
                dfs(self, edges[i], st)
                return
            elif preorder[edges[i]] >= st:
                self.ans = max(self.ans, preorder[i] - preorder[edges[i]] + 1)
                return
        
        for i in range(len(edges)):
            if preorder[i] == -1 and edges[i] != -1:
                dfs(self, i, self.pre)
        
        return self.ans
