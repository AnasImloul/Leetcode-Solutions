from heapq import heappop,heappush
from collections import defaultdict

class Solution:
    def secondMinimum(self, n: int, edges: List[List[int]], time: int, change: int) -> int:
        G = defaultdict(list)
        dist = defaultdict(set)
        for v, w in edges:
            G[v].append(w)
            G[w].append(v)
        h = [(0, 1)]
        res = []
        while h:
            d, v = heappop(h)
            if len(dist[v]) > 1:
                continue
            if d in dist[v]:
                continue
            dist[v].add(d)
            q, r = divmod(d, change)
            if q%2 == 1:
                d += change - r
            for w in G[v]:
                if w == n:
                    if  res:
                        if d+time not in res:
                            return d+time
                    else:
                        res.append(d+time)
                if len(dist[w]) < 2:
                    heappush(h, (d+time,w))
