// Runtime: 36 ms (Top 86.27%) | Memory: 16.90 MB (Top 84.26%)

class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        ans = 0
        table = [0] * len(nums)

        for r in range(2, len(nums)):
            diff1 = nums[r] - nums[r-1]
            diff2 = nums[r-1] - nums[r-2]

            if diff1 == diff2:
                table[r] = table[r-1] + 1
                ans += table[r-1] + 1

        return ans
