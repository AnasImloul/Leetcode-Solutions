# Runtime: 470 ms (Top 64.29%) | Memory: 16.1 MB (Top 38.57%)
class Solution:
    def ways(self, pizza: List[str], k: int) -> int:
        m, n = len(pizza), len(pizza[0])

        suffix = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m - 1, -1, -1):
            for j in range(n):
                suffix[i][j] = suffix[i + 1][j] + (pizza[i][j] == 'A')

        for i in range(m):
            for j in range(n - 1, -1, -1):
                suffix[i][j] += suffix[i][j + 1]

        MOD = 10 ** 9 + 7

        @lru_cache(None)
        def helper(top, left, cuts):
            if cuts == 0:
                return 1 if suffix[top][left] else 0

            res = 0
            for i in range(top + 1, m):
                if suffix[top][left] != suffix[i][left]:
                    res = (res + helper(i, left, cuts - 1)) % MOD

            for j in range(left + 1, n):
                 if suffix[top][left] != suffix[top][j]:
                    res = (res + helper(top, j, cuts - 1)) % MOD

            return res

        return helper(0, 0, k - 1)