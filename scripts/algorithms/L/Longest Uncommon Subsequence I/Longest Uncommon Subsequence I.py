# Runtime: 47 ms (Top 54.94%) | Memory: 13.9 MB (Top 58.35%)
class Solution:
    def findLUSlength(self, a: str, b: str) -> int:
        if a == b:
            return -1

        else:
            return max(len(a), len(b))