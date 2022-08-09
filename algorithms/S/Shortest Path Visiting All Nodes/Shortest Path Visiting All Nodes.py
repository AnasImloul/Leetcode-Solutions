class Solution:
    def shortestPathLength(self, graph: List[List[int]]) -> int:
        n = len(graph)
        fullmask = (1 << n) - 1
        used = [set() for i in range(n)]
        q = deque()
        state = 1
        for i in range(n):
            q.append([i, state])
            used[i].add(state)
            state <<= 1
        d = -1
        while q:
            d += 1
            for _ in range(len(q)):
                v, mask = q.popleft()
                if mask == fullmask:
                    return d
                for u in graph[v]:
                    newMask = mask | (1 << u)
                    if newMask not in used[u]:
                        q.append([u, newMask])
                        used[u].add(newMask)
        return 0
