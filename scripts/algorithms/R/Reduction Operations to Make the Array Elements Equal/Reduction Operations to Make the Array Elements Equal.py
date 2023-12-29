// Runtime: 717 ms (Top 99.99%) | Memory: 24.60 MB (Top 36.15%)

class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        ans = val = 0
        nums.sort()
        for i in range(1, len(nums)): 
            if nums[i-1] < nums[i]: val += 1
            ans += val
        return ans 
