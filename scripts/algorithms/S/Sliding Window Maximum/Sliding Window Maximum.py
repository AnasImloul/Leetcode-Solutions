# Runtime: 4951 ms (Top 7.51%) | Memory: 39.4 MB (Top 5.02%)
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        pq = []

        for i in range(k): heapq.heappush(pq,(-nums[i],i))

        ans.append(-pq[0][0])

        for i in range(k,len(nums)):
            heapq.heappush(pq,(-nums[i],i))
            while pq and pq[0][1] < i-k+1 : heapq.heappop(pq)
            ans.append(-pq[0][0])

        return ans