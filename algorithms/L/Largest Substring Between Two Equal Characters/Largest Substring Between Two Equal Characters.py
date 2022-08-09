class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        last, ans = {}, -1 
        for i, c in enumerate(s):
            if c not in last:
                last[c] = i
            else:
                ans = max(ans, i - last[c] - 1)
        return ans 
