class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        
        cache = {}
        def dfs(i, buying):
            
            if i >= len(prices):
                return 0
            
            if (i, buying) in cache:
                return cache[(i, buying)]
            
            if buying:
                # if have sell the share in previous step
                # then currently we have two options
                # either buy or not buy(cooldown)
                
                # we have bought so, increment the index and set buying flag to not buying
                # and don't forget that we bought so, we have to reduce that share amount from profit
                buy = dfs(i+1, not buying) - prices[i] 
                
                cooldown = dfs(i+1, buying)
                
                profit = max( buy, cooldown )
                cache[(i, buying)] = profit
                
            else:
                # we have sell the share so, 
                # we cannot buy next share we have to skip the next price(cooldown for one day)
                # set (not buying) flag to buying
                # we also have to add that share price to profit
                sell = dfs(i+2, not buying) + prices[i] 
                
                cooldown = dfs(i+1, buying)
                
                profit = max( sell, cooldown )
                cache[(i, buying)] = profit
                
            return cache[(i,  buying)]
        
        return dfs(0, True)

