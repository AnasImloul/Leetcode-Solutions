# Runtime: 163 ms (Top 31.64%) | Memory: 34.40 MB (Top 62.15%)

class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        n, result = len(nums), 0
        prefix, suffix = [0] * (n + 1), [0] * (n + 1)
        for i in range(1, n):
            prefix[i] = prefix[i - 1] | nums[i - 1]
            suffix[n - i - 1] = suffix[n - i] | nums[n - i]
        for i in range(n):
            result = max(result, prefix[i] | (nums[i] << k) | suffix[i])
        return result
