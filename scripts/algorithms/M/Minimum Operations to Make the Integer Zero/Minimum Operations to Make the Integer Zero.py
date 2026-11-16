# Runtime: 1 ms (Top 45.65%) | Memory: 19.10 MB (Top 98.91%)

class Solution:
    def makeTheIntegerZero(self, num1: int, num2: int) -> int:
        for k in range(61):
            target = num1 - k * num2
            if target >= 0 and target.bit_count() <= k <= target:
                return k
        return -1
