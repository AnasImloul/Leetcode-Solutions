# Runtime: 177 ms (Top 17.25%) | Memory: 15.5 MB (Top 9.55%)
class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        m = n//2
        median = nums[m]

        ans = 0
        for num in nums:
            ans += abs(num-median)
        return ans