// Runtime: 825 ms (Top 92.58%) | Memory: 31.60 MB (Top 21.29%)

class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target, n = sum(nums) - x, len(nums)
        
        if target == 0:
            return n
        
        max_len = cur_sum = left = 0
        
        for right, val in enumerate(nums):
            cur_sum += val
            while left <= right and cur_sum > target:
                cur_sum -= nums[left]
                left += 1
            if cur_sum == target:
                max_len = max(max_len, right - left + 1)
        
        return n - max_len if max_len else -1
