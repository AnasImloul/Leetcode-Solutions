class Solution:
    def minOperations(self, nums: List[int]) -> int:
        sol = 0
        last = nums[0]

        for i in range(len(nums) - 1):
            if last >= nums[i + 1]:
                sol += last - nums[i + 1] + 1
                last = last + 1
            else:
                last = nums[i + 1]
        
        return sol