class Solution:
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        poss = [(targetSeconds // 60, targetSeconds % 60)]  # store possibilities as (minutes, seconds)
        
        if poss[0][0] > 99:  # for when targetSeconds >= 6000
            poss = [(99, poss[0][1]+60)]
            
        if poss[0][0] >= 1 and (poss[0][1]+60) <= 99:
			# adding a second possibility e.g. (01, 16) -> (0, 76)
            poss.append((poss[0][0]-1, poss[0][1]+60))
            
        costs = list()
        
        for i in poss:
            curr_start = startAt
            curr_cost = 0
            
            minutes = str(i[0])
            if i[0] != 0:  # 0s are prepended, so no need to push 0s
                for j in minutes:
                    if int(j) != curr_start:
                        curr_cost += moveCost
                        curr_start = int(j)
                    curr_cost += pushCost
                    
            seconds = str(i[1])
            if len(seconds) == 1 and i[0] != 0:  # seconds is a single digit, prepend a "0" to it
                seconds = "0" + seconds
            
            for j in seconds:
                if int(j) != curr_start:
                    curr_cost += moveCost
                    curr_start = int(j)
                curr_cost += pushCost
            costs.append(curr_cost)
            
        return min(costs)