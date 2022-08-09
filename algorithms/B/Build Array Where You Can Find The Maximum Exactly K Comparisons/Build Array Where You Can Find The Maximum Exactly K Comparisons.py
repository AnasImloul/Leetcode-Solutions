class Solution:
    def numOfArrays(self, n: int, m: int, k: int) -> int:
        @cache
        def dp(a,b,c):
            if a==n: return c==k
            return (b*dp(a+1,b,c) if b>=1 else 0) + sum(dp(a+1,i,c+1) for i in range(b+1,m+1))
        return dp(0,0,0)%(10**9+7)
