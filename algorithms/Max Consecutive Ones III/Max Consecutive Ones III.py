class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        
        j = 0
        
        ans = 0
        
        result = -999999999
        
        for i in range(len(nums)):
            if nums[i]==0:
                ans+=1
            elif ans>k:
                result = max(result,j-i)

            while ans>k:
                if nums[j]==0:
                    ans-=1
                j+=1

        return max(result,i-j+1)