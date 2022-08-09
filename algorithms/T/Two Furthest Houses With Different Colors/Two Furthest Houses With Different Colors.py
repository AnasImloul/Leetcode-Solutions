class Solution:
    def maxDistance(self, colors: List[int]) -> int:
        p, res = inf, 0
        for i, c in enumerate(colors):
            if (c != colors[0]):
                res = i
                p = min(p, i)
            else:
                res = max(res, i - p)
        return res
