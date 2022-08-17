class Solution:
    def binaryGap(self, n: int) -> int:
        prev = 0
        res = 0
        for i, d in enumerate(bin(n)[3:]):
            if d == "1":
                res = max(res, i-prev+1)
                prev = i + 1
        return res
