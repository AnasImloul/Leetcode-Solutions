# Runtime: 159 ms (Top 46.41%) | Memory: 14.4 MB (Top 92.31%)
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:

        intervals.sort(key = lambda x: (x[0], -x[1]))
        current, count = intervals[0], 1
        for i in range(1, len(intervals)):
            if current[0] <= intervals[i][0] and intervals[i][1] <= current[1]:
                continue
            current = intervals[i]
            count += 1
        return count

# time and space complexity
# time: O(nlog(n))
# space: O(1)