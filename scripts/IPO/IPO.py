from heapq import heappush, heappop, nlargest
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        if w >= max(capital):
            return w + sum(nlargest(k, profits))
        
        projects = [[capital[i],profits[i]] for i in range(len(profits))]
        projects.sort(key=lambda x: x[0])
        
        heap = []
        
        for i in range(k):
            while projects and projects[0][0] <= w:
                heappush(heap, -1*projects.pop(0)[1])
            
            if not heap:
                break
            p = -heappop(heap)
            w += p
        return w
