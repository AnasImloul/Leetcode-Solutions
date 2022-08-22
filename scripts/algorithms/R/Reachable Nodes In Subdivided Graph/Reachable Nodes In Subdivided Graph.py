# Runtime: 1218 ms (Top 16.46%) | Memory: 23.7 MB (Top 8.86%)
class Solution:
    def reachableNodes(self, edges: List[List[int]], maxMoves: int, n: int) -> int:
        m = defaultdict(list)
        for a, b, p in edges:
            m[a].append((p, b))
            m[b].append((p, a))

        vis = set()
        queue = []
        heappush(queue, (0, 0))
        edgevis = set()
        edgeofl = defaultdict(lambda: 0)
        ans = 0
        while queue:
            # print(queue)
            cost, cur = heappop(queue)
            vis.add(cur)
            for p, nxt in m[cur]:
                if p < maxMoves - cost:
                    if (cur, nxt) not in edgevis and (nxt, cur) not in edgevis:
                        ans += p
                        # if nxt in vis:
                        # ans -= 1
                        edgevis.add((cur, nxt))
                        edgevis.add((nxt, cur))
                        if nxt not in vis:
                            heappush(queue, (cost + p + 1, nxt))
                else:
                    bal = maxMoves - cost
                    if (cur, nxt) in edgevis:
                        continue
                    if bal <= edgeofl[(cur, nxt)]:
                        continue
                    if bal + edgeofl[(nxt, cur)] < p:
                        ans += bal - edgeofl[(cur, nxt)]
                        edgeofl[(cur, nxt)] = bal
                    else:
                        ans += p - edgeofl[(nxt, cur)] - edgeofl[(cur, nxt)]
                        edgevis.add((cur, nxt))
                        edgevis.add((nxt, cur))
        return ans + len(vis)