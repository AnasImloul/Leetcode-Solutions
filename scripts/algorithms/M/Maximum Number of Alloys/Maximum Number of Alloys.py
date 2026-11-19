# Runtime: 288 ms (Top 36.84%) | Memory: 19.80 MB (Top 17.54%)

class Solution:
    def solve(self, mid, i, n, k, budget, composition, stock, cost):
        c = 0
        v = []
        for x in range(n):
            y = mid * composition[i][x]
            v.append(y)
        for x in range(n):
            if v[x] - stock[x] > 0:
                v[x] -= stock[x]
            else:
                v[x] = 0
            c += v[x] * cost[x]
            if c > budget:
                break
        return c <= budget

    def maxNumberOfAlloys(self, n, k, budget, composition, stock, cost):
        ans = 0
        for i in range(len(composition)):
            l, h = 0, int(1e9)
            s = 0
            while l <= h:
                mid = l + (h - l) // 2
                if self.solve(mid, i, n, k, budget, composition, stock, cost):
                    s = mid
                    l = mid + 1
                else:
                    h = mid - 1
            ans = max(ans, s)
        return ans
