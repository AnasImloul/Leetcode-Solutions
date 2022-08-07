class Solution:
    def isPallindrom(self, s: str, l, r) -> bool:
        st = s[l: r+1]
        rev = st[::-1]
        return st == rev
    
    def minCut(self, s: str) -> int:
        N = len(s)
        if not s: return 0
        if self.isPallindrom(s, 0, N-1): return 0
        dp = [sys.maxsize] * (N+1)
        dp[-1] = 0
        
        for i in range(N-1, -1, -1):
            for j in range(i, N):
                if self.isPallindrom(s, i, j):
                    dp[i] = min(dp[i], 1 + dp[j+1])
                    
        return dp[0]-1
