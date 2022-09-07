# Runtime: 301 ms (Top 20.49%) | Memory: 16.1 MB (Top 98.97%)
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        nums.sort()
        i=0
        while i<len(nums)-1:
            if nums[i]==nums[i+1]:
                i+=2
            else:
                return nums[i]

        return nums[-1]