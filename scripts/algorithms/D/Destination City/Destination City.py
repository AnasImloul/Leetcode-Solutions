# Runtime: 101 ms (Top 25.06%) | Memory: 13.8 MB (Top 81.64%)
from collections import defaultdict
class Solution:
    def destCity(self, paths: List[List[str]]) -> str:
        deg = defaultdict(int)
        for v, w in paths:
            deg[v] += 1
            deg[w]
        for v in deg:
            if not deg[v]: return v