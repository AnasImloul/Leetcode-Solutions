// Runtime: 79 ms (Top 10.08%) | Memory: 17.20 MB (Top 9.7%)

class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        while n > 1:
            n, r = divmod(n, 3)
            if r == 2: return False
        return True
