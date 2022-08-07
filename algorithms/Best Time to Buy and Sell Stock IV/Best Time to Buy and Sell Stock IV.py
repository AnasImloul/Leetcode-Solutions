class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        buy = [-inf] * (k+1)
        sell = [0] * (k+1)
        for price in prices:
            for i in range(1,k+1):
                    buy[i] = max(buy[i],sell[i-1]-price)
                    sell[i] = max(sell[i],buy[i]+price)
        return sell[-1]
