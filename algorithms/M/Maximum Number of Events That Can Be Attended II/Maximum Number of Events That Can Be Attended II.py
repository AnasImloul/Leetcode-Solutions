import bisect
from functools import lru_cache

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        if k == 1: # optimization for TLE test case 57/67
            return max([event[2] for event in events])
        
        events.sort()
        event_starts = [event[0] for event in events] # enables binary search
        
        @lru_cache(None)
        def dp(i, j):
            if j == 0: # out of turns
                return 0
            if i >= len(events): # end of events array
                return 0
            max_score = events[i][2]
            
            # get minimum index where start day is greater than current end day
            next_index_minimum = bisect.bisect_left(event_starts, events[i][1] + 1)
            
            # check each possibility from the minimum next index until end of the array
            for k in range(next_index_minimum, len(events)):
                max_score = max(max_score, events[i][2] + dp(k, j - 1))
            
            # check if we can get a better score if we skip this index altogether
            max_score = max(max_score, dp(i + 1, j))
            return max_score
        return dp(0, k)
