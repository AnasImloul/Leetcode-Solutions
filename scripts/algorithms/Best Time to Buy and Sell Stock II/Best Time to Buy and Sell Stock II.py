
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        ans=0
        want="valley"
        for i in range(n-1):
            if want=="valley" and prices[i]<prices[i+1]:
                ans-=prices[i]
                want="hill"
            elif want=="hill" and prices[i]>prices[i+1]:
                ans+=prices[i]
                want="valley"
        if want=="hill":
            ans+=prices[-1]
        return ans
