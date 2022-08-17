import heapq
class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        
        adjlist = [[] for _ in range(n+1)]
        
        for src, dst, weight in times:
            adjlist[src].append((dst, weight))
        
        visited = [-1]*(n+1)
        captured =[-1]*(n+1)

        priority_queue = [(0,k)]
    
        nums = 0
        total_dist = 0
        
        while priority_queue:

            dst, node = heapq.heappop(priority_queue)

            if captured[node] != -1:
                continue
            captured[node] = dst
            
            nums += 1
            total_dist = dst
            
            for nbr,wt in adjlist[node]:
                if captured[nbr] == -1:
                    heapq.heappush(priority_queue,(captured[node]+wt, nbr))
        if nums == n:
            return total_dist
        else:
            return -1
