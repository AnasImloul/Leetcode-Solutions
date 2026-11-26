# Runtime: 1171 ms (Top 25.47%) | Memory: 18.90 MB (Top 100.00%)

class Solution:
    def beautifulSubstrings(self, s: str, k: int) -> int:
        n = len(s)
        res = 0
        cc = ['a','e','i','o','u']
        for j in range(n):
            c,v=0,0
            for i in range(j,n):
                if s[i] in cc:
                    v += 1
                else:
                    c += 1
                if c==v and (c*v)%k==0:
                    res += 1
        return res
