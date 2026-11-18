# Runtime: 1485 ms (Top 41.27%) | Memory: 76.30 MB (Top 11.11%)

class Solution:
    def minOperationsQueries(self, n, edges, queries):
        m, C = n.bit_length() + 1, 27
        g = [[] for i in range(n)]
        for e in edges:
            g[e[0]].append((e[1], e[2]))
            g[e[1]].append((e[0], e[2]))

        # fa[i][j] means the 2^i -th father of vertex j:
        fa = [[0 for i in range(n)] for j in range(m)]
        # w[i][j] means the count of j from root to vertex i:
        w = [None for i in range(n)] 
        # d[i] means the depth of vertex i:
        d = [0] * n

        def dfs(x, f, dep):
            fa[0][x] = f  
            d[x] = dep 
            for (c, weight) in g[x]:
                if f == c: continue
                w[c] = w[x].copy()
                w[c][weight] += 1
                dfs(c, x, dep + 1)
        w[0] = [0] * C
        dfs(0, 0, 0)

        for i in range(1, m):
            for j in range(n):
                fa[i][j] = fa[i-1][fa[i-1][j]]

        def lca(x, y):
            if d[x] > d[y]: x, y = y, x
            # adjust x and y to the same depth:
            for p in range(m):
                if (1 << p) & (d[y] - d[x]): 
                    y = fa[p][y]
            # conservatively jump x and y together:
            for p in range(m-1, -1, -1):
                if fa[p][x] != fa[p][y]:
                    x = fa[p][x]
                    y = fa[p][y]
            return x if x == y else fa[0][x]

        res = []
        for q in queries:
            x, y, l = q[0], q[1], lca(q[0], q[1])
            # the total length between x and y:
            length = d[x] + d[y] - 2 * d[l]
            # the mode of weight between x and y:
            max_z = max([w[x][z] + w[y][z] - w[l][z] * 2 for z in range(1, C)])
            # the others must be changed:
            res.append(length - max_z)
        return res
