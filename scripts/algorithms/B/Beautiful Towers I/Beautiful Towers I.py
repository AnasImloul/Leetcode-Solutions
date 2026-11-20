# Runtime: 790 ms (Top 40.83%) | Memory: 19.30 MB (Top 87.50%)

class Solution:
    def maximumSumOfHeights(self, v):
        n = len(v)
        ans = 0
        for i in range(n):
            he = [0] * n
            he[i] = v[i]
            l, h = i - 1, i + 1
            while l >= 0:
                if v[l] <= he[l + 1]:
                    he[l] = v[l]
                else:
                    he[l] = he[l + 1]
                l -= 1
            while h < n:
                if v[h] <= he[h - 1]:
                    he[h] = v[h]
                else:
                    he[h] = he[h - 1]
                h += 1
            s = sum(he)
            ans = max(ans, s)
        return ans
