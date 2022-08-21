# Runtime: 804 ms (Top 69.55%) | Memory: 27.9 MB (Top 49.83%)

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