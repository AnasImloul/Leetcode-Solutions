# Runtime: 434 ms (Top 63.6%) | Memory: 40.12 MB (Top 13.9%)

class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        max_val = float('-inf')
        for i in range(n):
            max_val = max(max_val, nums[i])
            conver = nums[i] + max_val
            ans[i] = conver
        res=[]
        s=0
        for i in range(n):
            s+=ans[i]            
            res.append(s)
            
        return res
        