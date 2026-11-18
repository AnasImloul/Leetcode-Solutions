# Runtime: 41 ms (Top 94.68%) | Memory: 19.30 MB (Top 7.45%)

class Solution:
    def isReachableAtTime(self, sx: int, sy: int, fx: int, fy: int, t: int) -> bool:
        x_dist = abs(sx - fx)
        y_dist = abs(sy - fy)

        if x_dist == 0 and y_dist == 0:
            return t != 1

        return x_dist <= t and y_dist <= t
