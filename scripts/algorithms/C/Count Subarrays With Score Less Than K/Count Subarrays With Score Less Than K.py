// Runtime: 1779 ms (Top 5.03%) | Memory: 31.30 MB (Top 6.6%)

class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        sum, res, j = 0, 0, 0
        for i, n in enumerate(nums):
            sum += n
            while sum * (i - j + 1) >= k:
                sum -= nums[j]
                j += 1
            res += i - j + 1
        return res
