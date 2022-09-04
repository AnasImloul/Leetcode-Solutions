# Runtime: 990 ms (Top 41.71%) | Memory: 47.5 MB (Top 21.04%)
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        n = len(startTime)
        jobs = list(zip(startTime, endTime, profit))
        jobs.sort()
        startTime.sort()
        @lru_cache(None)
        def recur(i):
            if i == n:
                return 0
            j = bisect_left(startTime, jobs[i][1])
            one = jobs[i][2] + recur(j)
            two = recur(i+1)
            return max(one, two)
        return recur(0)