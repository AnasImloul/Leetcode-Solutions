# Runtime: 73 ms (Top 19.18%) | Memory: 13.9 MB (Top 56.58%)
import math
class Solution:
    def isThree(self, n: int) -> bool:
        primes = {3:1, 5:1, 7:1, 11:1, 13:1, 17:1, 19:1, 23:1, 29:1, 31:1, 37:1, 41:1, 43:1, 47:1, 53:1, 59:1, 61:1, 67:1, 71:1, 73:1, 79:1, 83:1, 89:1, 97:1}
        if n == 4:
            return True
        else:
            a = math.sqrt(n)

            if primes.get(a,0):
                return True
            else:
                return False