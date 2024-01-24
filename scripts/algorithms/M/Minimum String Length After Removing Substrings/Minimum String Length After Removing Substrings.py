// Runtime: 39 ms (Top 90.18%) | Memory: 16.50 MB (Top 65.09%)

class Solution:
    def minLength(self, s: str) -> int:

        prev = len(s)+1

        while len(s) < prev: s, prev = s.replace('AB', '' ).replace('CD', ''), len(s)
        
        return prev
