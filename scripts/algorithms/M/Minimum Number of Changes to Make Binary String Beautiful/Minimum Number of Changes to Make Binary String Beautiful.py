# Runtime: 19 ms (Top 43.97%) | Memory: 19.50 MB (Top 69.56%)

class Solution:
    def minChanges(self, s: str) -> int:
        return sum(s[i]!=s[i+1] for i in range(0, len(s), 2))
