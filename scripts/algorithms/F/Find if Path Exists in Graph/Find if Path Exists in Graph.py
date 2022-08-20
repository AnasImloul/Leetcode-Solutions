# Runtime: 4426 ms (Top 5.00%) | Memory: 313.2 MB (Top 8.29%)

class Solution:
    def validPath(self, n: int, edges: List[List[int]], start: int, end: int) -> bool:
        graph = self.buildGraph(edges)
        return self.hasPath(graph, start, end, set())

    # function to convert list of edges to adjacency list graph
    def buildGraph(self, edges):
        graph = {}
        for edge in edges:
            a, b = edge
            if a not in graph:
                graph[a] = []
            if b not in graph:
                graph[b] = []
            graph[a].append(b)
            graph[b].append(a)
        return graph

    def hasPath(self, graph, src, dst, visited):
        if src == dst:
            return True
        if src in visited:
            return False
        visited.add(src)
        for neighbour in graph[src]:
            if self.hasPath(graph, neighbour, dst, visited) == True:
                return True
        return False