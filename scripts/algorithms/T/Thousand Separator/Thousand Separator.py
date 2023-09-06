# Runtime: 44 ms (Top 29.7%) | Memory: 16.32 MB (Top 23.9%)

class Solution:
    def thousandSeparator(self, n: int) -> str:
        s=str(n)
        s=s[::-1]
        res = '.'.join(s[i:i + 3] for i in range(0, len(s), 3))
        return res[::-1]