class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #number mapped to idx... curr subarray ke mappings honge to check repeititions
        maps = {}
        ans = 0
        
        l, r = 0, 0
        curr = 0
        
        while r < len(nums):
            
            while l < r and (len(maps) >= k or nums[r] in maps):
                curr -= nums[l]
                maps.pop(nums[l])
                l += 1
            
            curr += nums[r]
            maps[nums[r]] = r
            
            if len(maps) == k:
                ans = max(curr, ans)
            
            r += 1
            
        
            
        return ans