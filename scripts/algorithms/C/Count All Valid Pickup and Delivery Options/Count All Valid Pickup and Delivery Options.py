class Solution:
    def countOrders(self, n: int) -> int:
        total = 1
        mod = 10 ** 9 + 7
        for k in reversed(range(2, n + 1)):
            total = total * ((2 * k - 1) * (2 * k - 2) // 2 + 2 * k - 1)
            total = total % mod
        return total
