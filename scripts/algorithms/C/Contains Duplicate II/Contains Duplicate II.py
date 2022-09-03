# Runtime: 632 ms (Top 95.72%) | Memory: 27.2 MB (Top 74.47%)
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = {}
        for i, n in enumerate(nums):
            if n in seen and i - seen[n] <= k:
                    return True
            seen[n] = i
        return False