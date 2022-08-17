class Solution:
    def countHousePlacements(self, n: int) -> int:
        
        
        @lru_cache(None)
        def rec(i, k):
            
            # i is the index of the house 
            # k is the state of last house, 1 if there was a house on the last index else 0
            
            if i>=n:
                return 1
            
            elif k==0:
                return rec(i+1,1) + rec(i+1,0)
            
            else:
                return rec(i+1,0)
        
        
        
        #l1 are the combinations possible in lane 1, the final answer will be the square 
		#of of l1 as for every combination of l1 there will be "l1" combinations in lane2.
        
        l1 = rec(1,0) + rec(1,1)
        
        
        mod = 10**9 +7
        return pow(l1, 2, mod) #use this when there is mod involved along with power 
            
