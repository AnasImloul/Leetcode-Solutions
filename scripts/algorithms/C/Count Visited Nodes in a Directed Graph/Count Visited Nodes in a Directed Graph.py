# Runtime: 261 ms (Top 61.46%) | Memory: 37.60 MB (Top 76.04%)

class Solution:
    def fillCycle(self, edges: List[int], visited: List[bool], result: List[int], start: int):
        x, length = start, 0
        while not visited[x]:
            visited[x] = True
            length += 1
            x = edges[x]
        result[start] = length
        x = edges[start]
        while x != start:
            result[x] = length
            x = edges[x]

    def countVisitedNodes(self, edges: List[int]) -> List[int]:
        n = len(edges)
        indegree, result, visited, q, s = [0] * n, [0] * n, [False] * n, deque(), []
        for e in edges:
            indegree[e] += 1
        for i in range(n):
            if indegree[i] == 0:
                q.append(i)
        while q:
            x = q.popleft()
            s.append(x)
            visited[x] = True
            indegree[edges[x]] -= 1
            if indegree[edges[x]] == 0:
                q.append(edges[x])
        for i in range(n):
            if not visited[i]:
                self.fillCycle(edges, visited, result, i)
        while s:
            x = s.pop()
            result[x] = result[edges[x]] + 1
        return result
