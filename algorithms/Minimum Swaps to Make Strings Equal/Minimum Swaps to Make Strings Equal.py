class Solution:
    def minimumSwap(self, s: str, t: str) -> int:
        xy = yx = 0
        for i in range(len(s)):
            if s[i] != t[i]:
                if s[i] == 'x': xy += 1
                else: yx += 1
        if (xy + yx) % 2: return -1

        return xy//2 + yx//2 + 2*(xy%2)
