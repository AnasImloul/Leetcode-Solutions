# Runtime: 328 ms (Top 81.03%) | Memory: 35.30 MB (Top 5.17%)

class Solution:
    def maxFrequencyScore(self, nums: List[int], k: int) -> int:

        notValid = lambda l, n: (acc[l] + acc[n-l] - 2*acc[n//2] - 
                                                 nums[n//2]*(n%2) > k)

        nums.sort()
        acc = list(accumulate(nums, initial = 0))
        left = ans = 0

        for rght in range(len(nums)):
            while notValid(left, left+rght+1): left+= 1
            ans = max(ans, rght - left)

        return ans+1
