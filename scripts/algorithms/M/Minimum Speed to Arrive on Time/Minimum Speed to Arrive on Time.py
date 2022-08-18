# Runtime: 5298 ms (Top 60.74%) | Memory: 27.4 MB (Top 98.14%)

class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        # the speed upper is either the longest train ride: max(dist),
        # or the last train ride divide by 0.01: ceil(dist[-1] / 0.01).
        # notice: "hour will have at most two digits after the decimal point"
        upper = max(max(dist), ceil(dist[-1] / 0.01))
        #
        # the function to calcute total time consumed
        total = lambda speed: sum(map(lambda x: ceil(x / speed), dist[:-1])) + (dist[-1] / speed)
        # the case of impossible to arrive office on time
        if total(upper) > hour:
            return -1
        #
        # binary search: find the mimimal among "all" feasible answers
        left, right = 1, upper
        while left < right:
            mid = left + (right - left) // 2
            if total(mid) > hour:
                left = mid + 1 # should be larger
            else:
                right = mid # should explore a smaller one
        return right