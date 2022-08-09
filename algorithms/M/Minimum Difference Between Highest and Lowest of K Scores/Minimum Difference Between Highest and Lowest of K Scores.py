class Solution:
    def minimumDifference(self, nums: List[int], k: int) -> int:
        nums.sort()
        cur = float('inf')
        for i in range(len(nums)-k+1):
            cur = min(cur, nums[i+k-1]-nums[i])
