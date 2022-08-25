// Runtime: 48 ms (Top 64.16%) | Memory: 13.9 MB (Top 24.70%)
class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n:
            n, rem = divmod(n, 3)
            if rem == 2:
                return False
        return True