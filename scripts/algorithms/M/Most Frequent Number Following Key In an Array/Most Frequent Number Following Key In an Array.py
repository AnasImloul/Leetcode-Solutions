# Runtime: 90 ms (Top 49.1%) | Memory: 16.67 MB (Top 9.2%)

class Solution:
    def mostFrequent(self, nums: List[int], key: int) -> int:
        l = [t for k,t in zip(nums, nums[1:]) if k == key]
        return max(set(l), key = l.count)