from heapq import heappush, heappop, heapify
class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        # pairs = list(combinations(nums, 2))
        
        maxHeap = []
        heapify(maxHeap)
        
        for idx, val1 in enumerate(nums):
            for val2 in nums[idx + 1:]:
                pair = [val1, val2]
                heappush(maxHeap, [-1*abs(pair[0] - pair[1]), pair])
                if len(maxHeap) > k:
                    heappop(maxHeap)
        
        return -1*maxHeap[0][0]
