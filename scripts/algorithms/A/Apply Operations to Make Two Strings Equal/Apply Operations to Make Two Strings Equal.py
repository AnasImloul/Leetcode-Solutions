# Runtime: 4 ms (Top 52.38%) | Memory: 20.70 MB (Top 45.24%)

from functools import cache
class Solution:
    def minOperations(self, s1: str, s2: str, x: int) -> int:
        N = len(s1)

        # list of indexes where the bits differ
        diffs = [i for i, a, b in zip(range(N), s1, s2) if a != b]

        # if there are an odd number of differences, it's impossible
        if len(diffs) % 2 == 1:
            return -1


        @cache
        def bestCostUpTo(i: int):
            # Returns the lowest cost to correct all diffs 
            #  up to and including diffs[i]

            if i == 0:
                return x / 2
            if i == -1:
                return 0
            return min(
                bestCostUpTo(i - 1) + x / 2,
                bestCostUpTo(i - 2) + diffs[i] - diffs[i - 1]
            )

        return int(bestCostUpTo(len(diffs) - 1))
