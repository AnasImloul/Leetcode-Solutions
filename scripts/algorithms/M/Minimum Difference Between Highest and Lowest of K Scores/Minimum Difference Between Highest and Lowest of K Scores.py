// Runtime: 118 ms (Top 7.93%) | Memory: 17.50 MB (Top 9.64%)

class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        m,n=100001,len(nums)
        i,j=0,k-1
        while j<n:
            m=min(m,nums[j]-nums[i])
            i+=1
            j+=1
        return m
