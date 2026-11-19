# Runtime: 371 ms (Top 63.82%) | Memory: 85.90 MB (Top 65.53%)

class Solution:
    def minEdgeReversals(self, n: int, edges: List[List[int]]) -> List[int]:

        g, ans, zeroCnt = defaultdict(list), defaultdict(int), 0

        for u, v in edges:
            g[u].append((v, 1))
            g[v].append((u,-1))

        queue = deque([(0,0)])

        while queue:
             par, parCnt = queue.pop()
             ans[par] = parCnt

             for chd,cnt in g[par]:
                if chd in ans: continue
                zeroCnt+= cnt
                queue.append((chd,cnt+parCnt))

        ans0 = (n-1-zeroCnt)//2
        return [ans[i] + ans0 for i in range(n)]
