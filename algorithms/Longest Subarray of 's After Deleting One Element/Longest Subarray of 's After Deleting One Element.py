class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        pre, suf = [1]*n, [1]*n
        if nums[0] == 0:pre[0] = 0
        if nums[-1] == 0:suf[-1] = 0
        
        for i in range(1, n):
            if nums[i] == 1 and nums[i-1] == 1:
                pre[i] = pre[i-1] + 1
            elif nums[i] == 0:
                pre[i] = 0
        
        for i in range(n-2, -1, -1):
            if nums[i] == 1 and nums[i+1] == 1:
                suf[i] = suf[i+1] + 1
            elif nums[i] == 0:
                suf[i] = 0
        
        ans = 0
        for i in range(n):
            if i == 0:
                ans = max(ans, suf[i+1])
            elif i == n-1:
                ans = max(ans, pre[i-1])
            else:
                ans = max(ans, pre[i-1] + suf[i+1])
        
        return ans