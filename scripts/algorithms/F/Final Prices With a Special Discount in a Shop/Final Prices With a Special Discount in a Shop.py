// Runtime: 47 ms (Top 83.49%) | Memory: 16.60 MB (Top 61.19%)

class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        for i in range(len(prices)):
          for j in range(i+1,len(prices)):
            if prices[j]<=prices[i]:
              prices[i]=prices[i]-prices[j]
              break
        return (prices)
