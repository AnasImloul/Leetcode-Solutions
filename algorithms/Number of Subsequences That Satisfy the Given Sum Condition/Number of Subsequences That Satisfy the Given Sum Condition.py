class Solution:
    def numSubseq(self, nums, target):
        nums.sort()
        l, r = 0, len(nums) - 1
        ans = 0
        mod = int(1e9+7)
        while l <= r:
            if nums[l] + nums[r] > target:
                r -= 1
            else:
                ans += pow(2, r-l, mod)
                l += 1
        return ans % mod
