class Solution:
    def minTimeToType(self, word: str) -> int:
        prev = "a"
        res = 0
        for c in word:
            gap = abs(ord(c)-ord(prev))
            res += min(gap, 26 - gap)
            prev = c
        return res + len(word)
