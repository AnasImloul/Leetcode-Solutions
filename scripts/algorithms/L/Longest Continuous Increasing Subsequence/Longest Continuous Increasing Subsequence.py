# Runtime: 416 ms (Top 5.00%) | Memory: 15.4 MB (Top 49.36%)

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        count=0
        for i in range(len(nums)):
            a=nums[i]
            c=1
            for j in range(i+1, len(nums)):
                if nums[j]>a:
                    a=nums[j]
                    c+=1
                else:
                    break
            count=max(count, c)
        return count