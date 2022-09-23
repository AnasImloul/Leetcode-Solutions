# Runtime: 4163 ms (Top 80.92%) | Memory: 673.9 MB (Top 5.26%)
class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)

        @lru_cache(None)
        def pal(i,j):
            if i == j:
                return True
            if s[i] != s[j]:
                return False
            if i+1 == j:
                return True
            else:
                return pal(i+1,j-1)

        for i in range(n-2):
            if pal(0,i):
                for j in range(i+1,n-1):
                    if pal(i+1,j) and pal(j+1,n-1):
                        return True
        return False