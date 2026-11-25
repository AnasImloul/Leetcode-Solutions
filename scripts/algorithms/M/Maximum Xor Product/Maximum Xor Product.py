# Runtime: 3 ms (Top 60.09%) | Memory: 19.00 MB (Top 92.96%)

class Solution:
    def maximumXorProduct(self, a: int, b: int, n: int) -> int:
        for bt in (2**i for i in range(n)):
            if a * b < (a ^ bt) * (b ^ bt):
                a ^= bt
                b ^= bt
        return a * b % (10**9 + 7)
