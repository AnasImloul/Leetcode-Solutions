# Runtime: 1122 ms (Top 94.6%) | Memory: 55.39 MB (Top 46.4%)

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals = sorted(intervals, key = lambda x:x[1])
        remove = 0
        end = -100000
        for i in intervals:
            if i[0] >= end:
                end = i[1]
            else:
                remove += 1
        return remove
        