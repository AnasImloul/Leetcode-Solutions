class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        return round(log(n,3), 9) == round(log(n,3)) if n >= 1 else False
