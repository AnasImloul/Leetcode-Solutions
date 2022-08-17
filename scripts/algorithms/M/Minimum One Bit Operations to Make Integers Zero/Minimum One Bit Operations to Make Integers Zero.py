class Solution:
    def minimumOneBitOperations(self, n: int) -> int:
        if n <= 1:
            return n
        def leftmostbit(x):
            x |= x >> 1
            x |= x >> 2
            x |= x >> 4
            x |= x >> 8
            x |= x >> 16
            x += 1
            x >>= 1
            return x
        x = leftmostbit(n)
        return ((x << 1) - 1) - self.minimumOneBitOperations(n - x)
