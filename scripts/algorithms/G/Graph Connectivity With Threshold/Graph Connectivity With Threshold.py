# Runtime: 881 ms (Top 97.89%) | Memory: 49.3 MB (Top 35.92%)
class Solution:
    def areConnected(self, n: int, threshold: int, queries: List[List[int]]) -> List[bool]:
        parent = list(range(n+1))
        def find(i):
            if parent[i] != i:
                parent[i] = find(parent[i])
            return parent[i]
        def union(i,j):
            parent[find(i)] = find(j)
        if not threshold: return [True]*len(queries)
        for i in range(1, n+1):
            for j in range(2*i, n+1, i):
                if i > threshold: union(i,j)
        return [find(i) == find(j) for i,j in queries]