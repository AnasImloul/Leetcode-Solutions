// Runtime: 77 ms (Top 96.60%) | Memory: 13.8 MB (Top 57.97%)
class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return round(log(n,3), 9) == round(log(n,3)) if n >= 1 else False