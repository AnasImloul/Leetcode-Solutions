// Runtime: 190 ms (Top 92.53%) | Memory: 22.10 MB (Top 78.57%)

from math import inf


class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        res = 0
        r1_min1 = inf
        r1_min2 = inf
        r2_min1 = inf
        r2_min2 = inf

        for v in nums:
            res += v
            if v % 3 == 1:
                if v < r1_min1:
                    r1_min2 = r1_min1
                    r1_min1 = v
                elif v < r1_min2:
                    r1_min2 = v
            elif v % 3 == 2:
                if v < r2_min1:
                    r2_min2 = r2_min1
                    r2_min1 = v
                elif v < r2_min2:
                    r2_min2 = v

        if res % 3 == 1:
            res -= min(r1_min1, r2_min1 + r2_min2)
        elif res % 3 == 2:
            res -= min(r2_min1, r1_min1 + r1_min2)

        return res
