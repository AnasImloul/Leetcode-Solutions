# Runtime: 5534 ms (Top 5.35%) | Memory: 55.9 MB (Top 70.78%)
class Solution:
    def countRestrictedPaths(self, n: int, edges: List[List[int]]) -> int:
        graph = collections.defaultdict(list) # build graph
        for a, b, w in edges:
            graph[a].append((w, b))
            graph[b].append((w, a))
        heap = graph[n]
        heapq.heapify(heap)
        d = {n: 0}
        while heap: # Dijkstra from node `n` to other nodes, record shortest distance to each node
            cur_w, cur = heapq.heappop(heap)
            if cur in d: continue
            d[cur] = cur_w
            for w, nei in graph[cur]:
                heapq.heappush(heap, (w+cur_w, nei))
        graph = collections.defaultdict(list)
        for a, b, w in edges: # pruning based on `restricted` condition, make undirected graph to directed-acyclic graph
            if d[a] > d[b]:
                graph[a].append(b)
            elif d[a] < d[b]:
                graph[b].append(a)
        ans, mod = 0, int(1e9+7)
        @cache
        def dfs(node): # use DFS to find total number of paths
            if node == n:
                return 1
            cur = 0
            for nei in graph[node]:
                cur = (cur + dfs(nei)) % mod
            return cur
        return dfs(1)