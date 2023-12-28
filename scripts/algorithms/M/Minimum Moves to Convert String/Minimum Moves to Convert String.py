// Runtime: 64 ms (Top 5.43%) | Memory: 17.30 MB (Top 11.89%)

class Solution:
    def minimumMoves(self, s: str) -> int:
        ans = i = 0
        while i < len(s): 
            if s[i] == "X": 
                ans += 1
                i += 3
            else: i += 1
        return ans 
