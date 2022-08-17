class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = 1
		# To keep track of starting element of each subsequence
        start = nums[0]
        
        for i in range(1, len(nums)):
            diff = nums[i] - start
            if diff > k:
				# If difference of starting and current element of subsequence is greater
				# than K, then only start new subsequence
                ans += 1
                start = nums[i]
        
        return ans