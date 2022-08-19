# Runtime: 867 ms (Top 26.03%) | Memory: 27.5 MB (Top 14.76%)

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums=[-n for n in nums]
        heapq.heapify(nums)
        while k>0:
            h=heapq.heappop(nums)
            k-=1
        return -h