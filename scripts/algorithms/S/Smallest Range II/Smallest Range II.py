// Runtime: 129 ms (Top 83.03%) | Memory: 18.50 MB (Top 25.76%)

class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]

        for i in range(0, len(nums) - 1):
            ans = min(ans, max(nums[i] + k, nums[-1] -
                      k) - min(nums[i+1] - k, nums[0] + k))

        return ans
