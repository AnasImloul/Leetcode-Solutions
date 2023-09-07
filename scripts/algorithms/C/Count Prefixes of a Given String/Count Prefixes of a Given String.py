# Runtime: 74 ms (Top 25.9%) | Memory: 16.47 MB (Top 86.6%)

class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        return len([i for i in words if s.startswith(i)])