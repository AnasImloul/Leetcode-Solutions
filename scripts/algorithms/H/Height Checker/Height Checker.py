class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        heightssort = sorted(heights)
        import numpy as np
        diff = list(np.array(heightssort) - np.array(heights))
        return (len(diff) - diff.count(0))
