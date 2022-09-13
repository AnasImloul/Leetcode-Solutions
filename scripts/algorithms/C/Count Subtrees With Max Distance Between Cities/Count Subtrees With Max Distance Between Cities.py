# Runtime: 2577 ms (Top 35.48%) | Memory: 14.1 MB (Top 20.97%)
from collections import defaultdict
class Solution:
    def countSubgraphsForEachDiameter(self, n: int, edges: List[List[int]]) -> List[int]:
        def floydwarshall(n, edges):
            D = [[float('inf')]*n for _ in range(n)]
            for u, v in edges:
                D[u-1][v-1] = 1
                D[v-1][u-1] = 1
            for v in range(n):
                D[v][v] = 0
            for k in range(n):
                for i in range(n):
                    for j in range(n):
                        D[i][j] = min(D[i][j],D[i][k]+D[k][j])
            return D

        G = defaultdict(list)
        for v, w in edges:
            G[v-1].append(w-1)
            G[w-1].append(v-1)

        def dfs(G, v, V, visited):
            if v in visited: return
            visited.add(v)
            for w in G[v]:
                if w in V:
                    dfs(G, w, V, visited)

        def check_connected(G, V):
            if not V: return False
            root = next(iter(V))
            visited = set()
            dfs(G, root, V, visited)
            return visited == V

        def max_distance(D, V):
            res = 0
            for v in V:
                for w in V:
                    res = max(res, D[v][w])
            return res

        def solve(include, idx, ans, G, D):
            if idx == n:
                V = set(v for v in range(n) if include[v])
                if check_connected(G, V):
                    d = max_distance(D, V)
                    if d >= 1:
                        ans[d-1] += 1
            else:
                solve(include, idx+1, ans, G, D)
                include[idx] = True
                solve(include, idx+1, ans, G, D)
                include[idx] = False

        D = floydwarshall(n, edges)
        include = [False] * n
        ans = [0]*(n-1)
        solve(include, 0, ans, G, D)
        return ans
