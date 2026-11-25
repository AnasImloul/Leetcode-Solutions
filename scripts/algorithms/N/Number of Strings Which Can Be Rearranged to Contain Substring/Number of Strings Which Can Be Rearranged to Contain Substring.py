# Runtime: 45 ms (Top 89.74%) | Memory: 19.20 MB (Top 51.28%)

class Solution:
    def stringCount(self, n: int) -> int:
        mod = 10 ** 9 + 7
        return (
            + pow(26, n, mod)
            - (n + 75) * pow(25, n - 1, mod)
            + (2 * n + 72) * pow(24, n - 1, mod)
            - (n + 23) * pow(23, n - 1, mod)
        ) % mod
