# Runtime: 575 ms (Top 52.45%) | Memory: 19 MB (Top 20.00%)
class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        lps = [0]*n
        for i in range(1,n):
            j = lps[i-1]
            while j>0 and s[j] != s[i]:
                j = lps[j-1]
            if s[j] == s[i]:
                j += 1
            lps[i] = j
        l = lps[n-1]
        return s[:l]