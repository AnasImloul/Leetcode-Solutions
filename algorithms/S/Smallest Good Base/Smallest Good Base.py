class Solution:
    def smallestGoodBase(self, n: str) -> str:
        import math
        n = int(n)
        max_m = math.floor(math.log(n, 2))
        ans = 0
        for m in range(max_m, 0, -1):
            k = int(n ** (1 / m))
            if (k ** (m + 1)  - 1) // (k - 1) == n:
                return str(k)
        return str(n - 1)
