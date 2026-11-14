# Runtime: 2544 ms (Top 15.20%) | Memory: 32.20 MB (Top 96.00%)

from sortedcontainers import SortedList
class Solution:
    def getSubarrayBeauty(self, nums: List[int], k: int, x: int) -> List[int]:
        sl, ans = SortedList(), []
        for i, y in enumerate(nums):
            sl.add(y)
            if len(sl) > k: sl.remove(nums[i - k])
            if i >= k - 1: ans.append(min(0, sl[x - 1]))
        return ans
