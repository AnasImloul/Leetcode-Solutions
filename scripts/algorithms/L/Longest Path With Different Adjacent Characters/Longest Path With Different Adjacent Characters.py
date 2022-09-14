# Runtime: 5213 ms (Top 8.25%) | Memory: 84.5 MB (Top 93.36%)
from graphlib import TopologicalSorter

class Solution:
    def longestPath(self, parent: List[int], s: str) -> int:
        def lengths():
            downs = [[0] for _ in s]
            ts = TopologicalSorter(dict(enumerate(zip(parent))))
            for node in [*ts.static_order()][:0:-1]:
                yield 1 + sum(nlargest(2, downs[node]))
                if s[node] != s[parent[node]]:
                    downs[parent[node]].append(1 + max(downs[node]))
        return max(lengths())