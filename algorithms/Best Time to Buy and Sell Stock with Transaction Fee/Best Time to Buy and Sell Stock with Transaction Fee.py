class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        lookup = {}
        def f(ind, buy, lookup):
            
            if ind == n: return 0
            
            if (ind, buy) in lookup: return lookup[(ind, buy)]
            profit = 0
            if buy:
                profit = max(-prices[ind] + f(ind+1,0,lookup), f(ind+1, 1,lookup))
            else:
                profit = max(prices[ind] + f(ind+1,1,lookup) - fee, f(ind+1, 0,lookup))
                
            lookup[(ind,buy)] = profit
            return lookup[(ind,buy)]
        
        return f(0, 1,lookup)

