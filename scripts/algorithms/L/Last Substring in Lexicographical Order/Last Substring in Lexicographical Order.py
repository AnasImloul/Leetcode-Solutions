# Runtime: 273 ms (Top 82.1%) | Memory: 20.15 MB (Top 100.0%)

class Solution:
    def lastSubstring(self, s: str) -> str:
        i = 0
        j = 1
        k = 0
        n = len(s)
        while j + k < n:
            if s[i + k] == s[j + k]:
                k += 1
            elif s[i + k] > s[j + k]:
                j += k + 1
                k = 0
            elif s[i + k] < s[j + k]:
                i = max(i + k + 1, j)
                j = i + 1
                k = 0
        return s[i:]