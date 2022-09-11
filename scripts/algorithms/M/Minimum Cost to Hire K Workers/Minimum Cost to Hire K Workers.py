# Runtime: 198 ms (Top 98.00%) | Memory: 16.6 MB (Top 33.56%)
from heapq import heappush, heappop
class Solution:
    def mincostToHireWorkers(self, quality: List[int], wage: List[int], k: int) -> float:
        quality_efficiency = sorted([(wage[i]/quality[i],i) for i in range(len(quality))])
        e = quality_efficiency[k-1][0]
        heap = [-quality[i] for _, i in quality_efficiency[:k]]
        heapify(heap)
        total = -sum(heap)
        res = total*e
        for e, i in quality_efficiency[k:]:
            heappush(heap,-quality[i])
            total += quality[i] + heappop(heap)
            if total*e < res:
                res = total*e
        return res