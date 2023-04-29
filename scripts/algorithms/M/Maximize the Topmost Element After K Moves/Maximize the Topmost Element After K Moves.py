class Solution:
    def maximumTop(self, nums: List[int], k: int) -> int:
        if (len(nums) == 1):
            if k % 2 == 0:
                return nums[0]
            else:
                return -1

        sol = -1

        for idx in range(min(k + 1, len(nums))):
            if k == idx or k > (idx + 1):
                sol = max(sol, nums[idx])

        
        return sol
