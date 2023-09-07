# Runtime: 62 ms (Top 34.5%) | Memory: 18.09 MB (Top 39.7%)

class Solution:
    def soupServings(self, n: int) -> float:
        if n > 4451: 
            return 1.0
        n = (n + 24) // 25
        memo = dict()
        
        def dp(i, j):
            if (i, j) in memo:
                return memo[(i, j)]
            if i <= 0 and j <= 0: 
                return 0.5
            if i <= 0: 
                return 1.0
            if j <= 0: 
                return 0.0
            memo[(i, j)] = 0.25 * (dp(i - 4, j) + dp(i - 3, j - 1) + dp(i - 2, j - 2) + dp(i - 1, j - 3))
            return memo[(i, j)]
        
        return dp(n, n)