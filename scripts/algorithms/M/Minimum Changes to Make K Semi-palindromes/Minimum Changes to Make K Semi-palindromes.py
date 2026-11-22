# Runtime: 3070 ms (Top 30.06%) | Memory: 19.40 MB (Top 92.93%)

class Solution:
    def minimumChanges(self, st: str, k: int) -> int:
        def num(st):
            n = len(st)
            ans = float('inf')
            for it in fac[len(st)]:
                nu = n // it
                cur = 0
                for i in range(nu // 2):
                    i2 = nu - i - 1
                    for j in range(it):
                        if st[i * it + j] != st[i2 * it + j]:
                            cur += 1
                ans = min(ans, cur)
            return ans

        n = len(st)
        for i in range(2, n + 1):
            fac[i] = []
            for j in range(1, i):
                if i % j == 0:
                    fac[i].append(j)

        dp = [[float('inf')] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(n):
            for j in range(i + 1):
                cur = st[j:i + 1]
                add = num(cur)
                for l in range(k):
                    dp[i + 1][l + 1] = min(dp[i + 1][l + 1], dp[j][l] + add)

        return dp[n][k]

# Initialize the fac array.
fac = [[] for _ in range(210)]
