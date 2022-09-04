# Runtime: 75 ms (Top 31.13%) | Memory: 14 MB (Top 42.55%)
class Solution:
    def mostWordsFound(self, ss: List[str]) -> int:
        return max(s.count(" ") for s in ss) + 1