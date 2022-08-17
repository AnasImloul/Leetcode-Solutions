class Solution:
    def minRefuelStops(self, t, F, S):
        S.append([t, 0])
        heap, ans = [], 0
        for p,f in S:
            while heap and p > F:
                F -= heapq.heappop(heap)
                ans += 1
            if p > F: return -1
            heapq.heappush(heap, -f)
        return ans
