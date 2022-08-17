MOD = 10**9 + 7
class Solution:
    def maxNiceDivisors(self, n: int) -> int:
        if n <= 2: return n
        i, c = divmod(n, 3)
        if not c: return pow(3, i, MOD)
        return (self.maxNiceDivisors(n-2)*2) % MOD
