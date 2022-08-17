class Solution:
    def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
	        n:int = len(nextVisit)
        days:List[int] = n*[0] # days[i] is the number of days it takes to first reach room i
        MOD = pow(10, 9) + 7
        for i in range(0,n-1):
            # First we are already at room i. days[i] days has passed
            days[i+1] = days[i]
            # lets go from room i to room i+1. 
            # When we first visit room i, we need to visit room i again (so room i is visited twice, which is an even number), then we can visit room i+1
            # after we fist visit room i, the next day we will visit room (nextVisit[i]). 
            days[i+1] = (days[i+1] + 1) % MOD
            # Then the problem becomes "how to go from room (nextVisit[i]) back to room i". The step is (days[i] - days[nextVisit[i]])
            days[i+1] = (days[i+1] + days[i] - days[nextVisit[i]]) % MOD
            # Then, in the next day we go from room i to i+1
            days[i+1] = (days[i+1] + 1) % MOD
        
        return days[n-1]
