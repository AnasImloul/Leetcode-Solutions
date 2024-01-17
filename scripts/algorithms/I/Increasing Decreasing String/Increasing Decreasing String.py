// Runtime: 72 ms (Top 48.8%) | Memory: 17.70 MB (Top 9.21%)

class Solution:
    def sortString(self, s: str) -> str:
        s = list(s)
        result = ''
        while s:
            for letter in sorted(set(s)):
                s.remove(letter)
                result += letter
            for letter in sorted(set(s), reverse=True):
                s.remove(letter)
                result += letter
        return result
