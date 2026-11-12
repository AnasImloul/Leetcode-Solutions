# Runtime: 0 ms (Top 100.00%) | Memory: 19.30 MB (Top 65.30%)

class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:

        sums = (x+y for x,y in zip(nums[1:], nums))  # <-- 1)

        counts = Counter(sums).values()              # <-- 2)

        return max(counts) > 1                       # <-- 3)
