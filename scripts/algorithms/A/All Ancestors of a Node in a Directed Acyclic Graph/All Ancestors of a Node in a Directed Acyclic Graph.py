# Runtime: 2132 ms (Top 14.62%) | Memory: 30.4 MB (Top 89.89%)
class Solution:
    def getAncestors(self, n: int, edges: List[List[int]]) -> List[List[int]]:
        graph = {}
        for a, b in edges:
            graph[b] = graph.get(b, []) + [a]
        op = [[] for i in range(n)]
        for a in graph:
            visited = set()
            paths = [a]
            while len(paths) > 0:
                curr = paths.pop()
                for b in graph.get(curr, []):
                    if b not in visited:
                        visited.add(b)
                        paths.append(b)
            op[a] = sorted(visited)
        return op