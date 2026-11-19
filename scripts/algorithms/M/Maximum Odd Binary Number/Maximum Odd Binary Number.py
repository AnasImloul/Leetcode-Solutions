# Runtime: 1 ms (Top 54.22%) | Memory: 19.10 MB (Top 70.44%)

class Solution:
    def maximumOddBinaryNumber(self, s: str) -> str:
        sorted_s = sorted(s, reverse=True)
        for i in range(len(s) - 1, -1, -1):
            if sorted_s[i] == '1':
                sorted_s[i], sorted_s[-1] = sorted_s[-1], sorted_s[i]
                break
        return ''.join(sorted_s)
