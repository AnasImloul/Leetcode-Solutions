// Runtime: 201 ms (Top 33.23%) | Memory: 18.20 MB (Top 28.53%)

class Solution:
    def appealSum(self, s: str) -> int:
        res, n, prev = 0, len(s), defaultdict(lambda: -1)
        for i, ch in enumerate(s):
            res += (i - prev[ch]) * (n - i)
            prev[ch] = i
        return res
