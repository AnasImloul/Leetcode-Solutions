import sys
class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int: 
        def calculate(k,ans):
            if k>1:
                ans+=((k-1)*(k))//2 
				#Sum of Natural Numbers
                return ans
            else:
                return ans
        end = 0
        start = 0
        prev= sys.maxsize
        k= 0
        ans = 0
        while end<len(prices):     
            if prev- prices[end]==1 or prev == sys.maxsize:
                k+=1
                prev = prices[end]
                end+=1    
            else:             
                ans = calculate(k,ans)
                start = end
                if end<len(prices):
                    prev = sys.maxsize
                k=0
        if k>1:
            ans = calculate(k,ans)
			
        return ans+len(prices)
