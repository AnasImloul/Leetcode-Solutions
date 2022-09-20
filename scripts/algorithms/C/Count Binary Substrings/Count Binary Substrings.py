# Runtime: 609 ms (Top 8.10%) | Memory: 14.5 MB (Top 82.48%)
class Solution:
    def countBinarySubstrings(self, s: str) -> int:
        n = len(s)
        ctrs = []
        i = 0
        while i < n:
            ctr = 1
            while i < n - 1 and s[i] == s[i + 1]:
                ctr += 1
                i += 1
            i += 1
            ctrs.append(ctr)
        res = 0
        k = len(ctrs)
        for i in range(k - 1):
            res += min(ctrs[i], ctrs[i + 1])
        return res