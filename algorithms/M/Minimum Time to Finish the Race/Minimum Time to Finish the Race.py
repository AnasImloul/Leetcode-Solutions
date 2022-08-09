class Solution:
    def minimumFinishTime(self, tires: List[List[int]], changeTime: int, numLaps: int) -> int:
        # by observation, we can try to find out the optimal usage within certain numLaps
        # use DP
        # the optimal usage of this lap = min(change tire , no change)
        # dp(laps) = min( dp(laps-1)+dp(1) + dp(laps-2)+dp(2) + ...)
        
        # we don't want to use tires too many laps, which will create unrealistic single lap time
		# we can evaluate single lap time by using changeTime <= 100000 and r >= 2
		# x = minimal continously laps
		# single lap time = 1*2^x <= 100000 -> x can't go more than 19
		limit = 19
        tires = list(set([(t1, t2) for t1, t2 in tires]))
        memo = [[(-1,-1) for _ in range(min(limit,numLaps)+1)] for _ in range(len(tires))]
        
        for i in range(len(tires)):
            for j in range(1, min(limit,numLaps)+1):                   # lap 1 to numLaps
                if j == 1:
                    memo[i][j] = (tires[i][0], tires[i][0])            # total time, lap time
                else:
                    # print('i, j', i, j)
                    tmp = memo[i][j-1][1]*tires[i][1]                  # cost of continuously use tire this lap
                    memo[i][j] = (memo[i][j-1][0]+tmp, tmp)
        
        @cache
        def dp(laps):
            if laps == 1:
                return min(memo[i][1][0] for i in range(len(tires)))
            
            # no change:
            best_time = min(memo[i][laps][0] for i in range(len(tires))) if laps <= limit else float('inf')
            
            # change tire:
			# e.g. change tire at this lap and see if it'll be faster -> dp(laps-1) + changeTime + dp(1)
            # check all previous laps: dp(a) + changeTime + dp(b) until a < b
            for j in range(1, laps):
                a, b = laps-j, j
                if a >= b:
                    ta = dp(a)
                    tb = dp(b)
                    if ta+tb+changeTime < best_time:
                        best_time = ta+tb+changeTime
            return best_time
                
        return dp(numLaps)
