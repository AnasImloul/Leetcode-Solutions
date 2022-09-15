# Runtime: 59 ms (Top 27.86%) | Memory: 13.9 MB (Top 62.57%)
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        stones = [-x for x in stones]
        heapq.heapify(stones)

        while len(stones) > 1:
            mx1 = -heapq.heappop(stones)
            mx2 = -heapq.heappop(stones)
            if mx1 - mx2:
                heapq.heappush(stones, -(mx1 - mx2))

        if len(stones):
            return -heapq.heappop(stones)
        return 0
