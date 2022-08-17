class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        nums.sort()
        sums, i, ans = 0, 0, 0
        for j in range(len(nums)):
            sums += nums[j]
            while nums[j]*(j-i+1) > sums+k:
                sums -= nums[i]
                i = i+1
            ans = max(ans, j-i+1)
        return ans