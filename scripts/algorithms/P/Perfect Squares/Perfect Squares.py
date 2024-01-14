// Runtime: 28 ms (Top 99.85%) | Memory: 17.30 MB (Top 57.47%)

class Solution:
    def isSquare(self, n: int) -> bool:
        sq = int(math.sqrt(n))
        return sq*sq == n
        
    def numSquares(self, n: int) -> int:
        # Lagrange's four-square theorem
        if self.isSquare(n):
            return 1
        while (n & 3) == 0:
            n >>= 2
        if (n & 7) == 7:
            return 4
        sq = int(math.sqrt(n)) + 1
        for i in range(1,sq):
            if self.isSquare(n - i*i):
                return 2
        return 3
