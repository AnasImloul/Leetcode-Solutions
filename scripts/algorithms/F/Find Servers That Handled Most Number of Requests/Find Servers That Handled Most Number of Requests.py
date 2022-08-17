class Solution:
    def busiestServers(self, k: int, A: List[int], B: List[int]) -> List[int]:
        available = list(range(k)) # already a min-heap
        busy = [] 
        res = [0] * k
        for i, a in enumerate(A):
            while busy and busy[0][0] <= a: # these are done, put them back as available
                _, x = heapq.heappop(busy)
                heapq.heappush(available, i + (x-i)%k) # invariant: min(available) is at least i, at most i+k-1
            if available: 
                j = heapq.heappop(available) % k
                heapq.heappush(busy, (a+B[i],j))
                res[j] += 1
        a = max(res)
        return [i for i in range(k) if res[i] == a]
