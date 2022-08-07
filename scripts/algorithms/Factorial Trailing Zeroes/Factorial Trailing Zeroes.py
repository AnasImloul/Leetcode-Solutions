class Solution:
    def trailingZeroes(self, n: int) -> int:
        res = 0
        for i in range(2, n+1):
            while i > 0 and i%5 == 0:
                i //= 5
                res += 1
        return res