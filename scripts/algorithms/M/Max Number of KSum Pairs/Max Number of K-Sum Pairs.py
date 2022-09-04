# Runtime: 919 ms (Top 63.81%) | Memory: 26.3 MB (Top 91.73%)
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        nums.sort()
        left = 0
        right = len(nums) - 1
        ans = 0
        while left < right:
            cur = nums[left] + nums[right]
            if cur == k:
                ans += 1
                left += 1
                right -= 1
            elif cur < k:
                left += 1
            else:
                right -= 1

        return ans