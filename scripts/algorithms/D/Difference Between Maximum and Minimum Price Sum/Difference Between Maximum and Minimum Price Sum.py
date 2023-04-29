class Solution:
    def maxOutput(self, n: int, edges: List[List[int]], price: List[int]) -> int:

        g = defaultdict(list)
        for a, b in edges: g[a].append(b) ;  g[b].append(a)

        def dfs(node1, node2 =-1):
            p = price[node1]
            state = (0, p, 0)

            for n in g[node1]:
                if n == node2: continue

                (a1, a2, a3), (b1, b2, b3) = state, dfs(n, node1)
                
                state = (max(a1, b1, a2 + b3, a3 + b2),
                         max(a2, b2 + p),
                         max(a3, b3 + p))

            return state

        if n <= 2: return sum(price) - min(price)

        for node in range(n):
            if len(g[node]) > 1:
                return dfs(node)[0]
