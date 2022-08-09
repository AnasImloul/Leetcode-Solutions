class Solution:
    def shortestSuperstring(self, A):
        @lru_cache(None)
        def suffix(i,j):
            for k in range(min(len(A[i]),len(A[j])),0,-1):
                if A[j].startswith(A[i][-k:]):
                    return A[j][k:]
            return A[j]
        n = len(A)
        @lru_cache(None)
        def dfs(bitmask, i):
            if bitmask + 1 == 1 << n: return ""
            return min([suffix(i, j)+dfs(bitmask | 1<<j, j) for j in range(n) if not(bitmask & 1<<j)], key = len)
        return min([A[i]+dfs(1<<i,i) for i in range(n)], key = len)