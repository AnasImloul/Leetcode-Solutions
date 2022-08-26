// Runtime: 2256 ms (Top 53.49%) | Memory: 63.7 MB (Top 23.26%)
from functools import lru_cache
class Solution:
    def getMaxGridHappiness(self, m: int, n: int, introvertsCount: int, extrovertsCount: int) -> int:
        def calc(x, y): #calculate interaction
            if x == 0 or y == 0:
                return 0
            if x == 1 and y == 1:
                return -60
            if x == 2 and y == 2:
                return 40
            return -10
        n3, highest = 3 ** n, 3 ** (n - 1)
        mask_all, rolling = {}, {}
        for mask in range(n3): #get every state in ternary expression
            tmp = mask
            ternary = []
            for _ in range(n):
                ternary.append(tmp % 3)
                tmp //= 3
            mask_all[mask] = ternary[::-1]
            rolling[mask] = [ #get the three states after a slide
                mask % highest * 3 + 0,
                mask % highest * 3 + 1,
                mask % highest * 3 + 2
            ]
        @lru_cache(None)
        def dfs(pos, borderline, i, e):
            if pos == m * n or not i and not e: #exit of dfs
                return 0
            x, y = divmod(pos, n)
            #put 0 in pos
            best = dfs(pos + 1, rolling[borderline][0], i, e)
            #put 1 in pos
            if i > 0:
                best = max(best, 120 + calc(1, mask_all[borderline][0]) +
                          (0 if y == 0 else calc(1, mask_all[borderline][n - 1])) +
                          dfs(pos + 1, rolling[borderline][1], i - 1, e))
            #put 2 in pos
            if e > 0:
                best = max(best, 40 + calc(2, mask_all[borderline][0]) +
                          (0 if y == 0 else calc(2, mask_all[borderline][n - 1])) +
                          dfs(pos + 1, rolling[borderline][2], i, e - 1))
            return best
        return dfs(0, 0, introvertsCount, extrovertsCount)