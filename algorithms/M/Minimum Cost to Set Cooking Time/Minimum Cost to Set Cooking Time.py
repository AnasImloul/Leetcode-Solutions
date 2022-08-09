class Solution:
    def minCostSetTime(self, startAt: int, moveCost: int, pushCost: int, targetSeconds: int) -> int:
        def count_cost(minutes, seconds): # Calculates cost for certain configuration of minutes and seconds
            time = f'{minutes // 10}{minutes % 10}{seconds // 10}{seconds % 10}' # mm:ss
            time = time.lstrip('0') # since 0's are prepended we remove the 0's to the left to minimize cost
            t = [int(i) for i in time]
            current = startAt
            cost = 0
            for i in t:
                if i != current:
                    current = i
                    cost += moveCost
                cost += pushCost
            return cost
        ans = float('inf')
        for m in range(100): # Check which [mm:ss] configuration works out
            for s in range(100):
                if m * 60 + s == targetSeconds: 
                    ans = min(ans, count_cost(m, s))
        return ans
