# Runtime: 498 ms (Top 63.4%) | Memory: 30.38 MB (Top 40.6%)

class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        if len(nums) == 1:
            if k%2 != 0:
                return -1
            return nums[0]
        
        if k == 0:
            return nums[0]
        if k == len(nums):
            return max(nums[:-1])
        if k > len(nums):
            return max(nums)
        if k == 1:
            return nums[1]
        m = max(nums[:k-1])
        m = max(m, nums[k])
        return m