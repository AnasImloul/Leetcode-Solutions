# Runtime: 1385 ms (Top 99.43%) | Memory: 59.9 MB (Top 71.02%)
class UnionFind:
    def __init__(self, n):
        self.roots = [i for i in range(n)]

    def find(self, v):
        if self.roots[v] != v:
            self.roots[v] = self.find(self.roots[v])

        return self.roots[v]

    def union(self, u, v):
        self.roots[self.find(u)] = self.find(v)

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        uf = UnionFind(len(source))
        for idx1, idx2 in allowedSwaps:
            uf.union(idx1, idx2)

        m = collections.defaultdict(set)
        for i in range(len(source)):
            m[uf.find(i)].add(i)

        res = 0
        for indices in m.values():
            freq = {}
            for i in indices:
                freq[source[i]] = freq.get(source[i], 0)+1
                freq[target[i]] = freq.get(target[i], 0)-1
            res += sum(val for val in freq.values() if val > 0)

        return res