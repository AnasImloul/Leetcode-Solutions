class Solution:
    def __init__(self):
        self.dp = {}
        
    def waysToFillArray(self, queries: List[List[int]]) -> List[int]:
        mod = 10 ** 9 + 7
        
        def dfs(n, val):
            if (n, val) not in self.dp:
                if n == 1: return 1
                temp = 1
                for k in range(val//2, 0, -1):
                    if val % k == 0:
                        temp += dfs(n-1, val // k)
                self.dp[n, val] = temp % mod
            return self.dp[n, val]
        
        res = []
        for n, val in queries:
            res.append(dfs(n, val))
        return res
