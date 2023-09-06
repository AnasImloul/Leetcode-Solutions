# Runtime: 180 ms (Top 81.5%) | Memory: 18.96 MB (Top 17.6%)

class Solution:
    def maximumCostSubstring(self, s: str, chars: str, vals: List[int]) -> int:
        i=1
        m=dict()
        for c in ascii_lowercase:
            if c in chars:
                m.update({c:vals[chars.index(c)]})
            else:
                m.update({c:i})
            i+=1
        xx=[]
        for i in range(len(s)):
            xx.append(m[s[i]])
        print(xx)
        def maxSubArray(nums: List[int]) -> int:
            max_sum=nums[0]
            temp=0
            for i in range(len(nums)):
                if temp<0:
                    temp=0
                temp+=nums[i]
                if temp>max_sum:
                    max_sum=temp
            return max_sum
        
        
        
        return max(maxSubArray(xx),0)