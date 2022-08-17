class Solution:
    def findPoisonedDuration(self, timeSeries: List[int], duration: int) -> int:
        
        """
        timeDur = (timeSeries[0], timeSeries[0] + duration - 1)
        i = 1
        total = 0
        while i < len(timeSeries):
            if timeSeries[i] > timeDur[1]:
                total += (timeDur[1] - timeDur[0] + 1)
            else:
                total += (timeSeries[i] - timeDur[0])
            timeDur = (timeSeries[i], timeSeries[i] + duration - 1)
            i += 1
        total += (timeDur[1] - timeDur[0] + 1)
        return total
        
        """
        # Between two interval, Ashe can be poisoned only for max duration time,
        # if time differece is less than duranton, then we that value
        total = 0
        for i in range(len(timeSeries)-1):
            total += min(duration, timeSeries[i+1] - timeSeries[i])
        return total + duration
            
