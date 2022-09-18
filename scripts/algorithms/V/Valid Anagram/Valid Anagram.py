# Runtime: 86 ms (Top 42.25%) | Memory: 14.4 MB (Top 67.11%)
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return Counter(s) == Counter(t)
