// Runtime: 447 ms (Top 43.48%) | Memory: 30.40 MB (Top 31.32%)

import heapq
from collections import defaultdict
class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        if not nums or not k:
            return []
        lo = [] # max heap
        hi = [] # min heap
        for i in range(k):
            if len(lo) == len(hi):
                heapq.heappush(hi, -heapq.heappushpop(lo, -nums[i]))
            else:
                heapq.heappush(lo, -heapq.heappushpop(hi, nums[i]))
        ans = [float(hi[0])] if k & 1 else [(hi[0] - lo[0]) / 2.0]
        to_remove = defaultdict(int)
        for i in range(k, len(nums)): # right bound of window
            heapq.heappush(lo, -heapq.heappushpop(hi, nums[i])) # always push to lo
            out_num = nums[i-k]
            if out_num > -lo[0]:
                heapq.heappush(hi, -heapq.heappop(lo))
            to_remove[out_num] += 1
            while lo and to_remove[-lo[0]]:
                to_remove[-lo[0]] -= 1
                heapq.heappop(lo)
            while to_remove[hi[0]]:
                to_remove[hi[0]] -= 1
                heapq.heappop(hi)
            if k % 2:
                ans.append(float(hi[0]))
            else:
                ans.append((hi[0] - lo[0]) / 2.0)
        return ans
