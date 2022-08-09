class Solution:
    def countPaths(self, n: int, roads: List[List[int]]) -> int:
        graph = defaultdict(dict)
        for u, v, w in roads:
            graph[u][v] = graph[v][u] = w
        dist = {i:float(inf) for i in range(n)}
        ways = {i:0 for i in range(n)}
        dist[0], ways[0] = 0, 1
        heap = [(0, 0)]
        while heap:
            d, u = heapq.heappop(heap)
            if dist[u] < d: 
                continue
            for v in graph[u]:
                if dist[v] == dist[u] + graph[u][v]:
                    ways[v] += ways[u]
                elif dist[v] > dist[u] + graph[u][v]:
                    dist[v] = dist[u] + graph[u][v]
                    ways[v] = ways[u]
                    heapq.heappush(heap, (dist[v], v))
        return ways[n-1] % ((10 ** 9) + 7)
