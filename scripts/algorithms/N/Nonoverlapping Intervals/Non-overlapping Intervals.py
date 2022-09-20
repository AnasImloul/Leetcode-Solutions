# Runtime: 3400 ms (Top 9.83%) | Memory: 52.7 MB (Top 60.76%)
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int: # Time: O(nlogn) and Space: O(1)
        intervals.sort()
        res = 0
        prevEnd = intervals[0][1]

        for start, end in intervals[1:]: # we will start from 1 as we already had taken 0 as a base value
            if start >= prevEnd: # Non overlapping when new interval starts after or from the previous one
                prevEnd = end # prev = [2, prevEnd=3] & new = [start=3, end=4], we have a new end now after checking the new non overlapping interval
            else: # Overlapping when new interval starts in between or from the previous one
                res += 1 # prev = [1, prevEnd=2] & new = [start=1, end=3] --> we will delete new=[1, 3] & set prev = [1, prevEnd=2]
                prevEnd = min(end, prevEnd) # we will delete on the interval on the basis of whose interval ends last

        return res