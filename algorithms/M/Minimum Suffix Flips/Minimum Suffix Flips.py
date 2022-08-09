class Solution:
    def minFlips(self, target: str) -> int:
        flip = False
        res = 0
        for c in target:
            if (c == '1') != flip:
                flip = not flip
                res += 1
        
        return res