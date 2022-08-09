class Solution:
    def minimumMoves(self, s: str) -> int:
        i, m = 0, 0
        l = len(s)

        while i < l:
            if s[i] != 'X':
                i += 1
            elif 'X' not in s[i:i+1]:
                i += 2
            elif 'X' in s[i:i+2]:
                m += 1
                i += 3
        return m
