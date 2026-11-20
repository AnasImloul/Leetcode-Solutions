# Runtime: 71 ms (Top 25.45%) | Memory: 29.60 MB (Top 45.45%)

class Solution:
    def maxSubarrays(self, v):
        m = 33554431
        n = len(v)

        for i in range(n):
            m = m & v[i]

        s = 33554431
        c = 0

        if m == 0:
            for i in range(n):
                s = s & v[i]
                if i == n - 1 and s != m:
                    return c
                if s == m:
                    s = 33554431
                    c += 1
            return c

        return 1
