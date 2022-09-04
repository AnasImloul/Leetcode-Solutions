# Runtime: 3042 ms (Top 71.65%) | Memory: 50.4 MB (Top 92.27%)
class Solution:
    def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
        m, n = len(matrix), len(matrix[0])
        rank = [0]*(m + n)
        d = defaultdict(list)
        for i in range(m):
            for j in range(n):
                d[matrix[i][j]].append((i,j))
        def find(i):
            if p[i] != i:
                p[i] = find(p[i])
            return p[i]
        def union(i,j):
            pi, pj = find(i), find(j)
            p[pi] = pj
            newrank[pj] = max(newrank[pi], newrank[pj])
        for e in sorted(d):
            p = list(range(m+n))
            newrank = rank[:]
            for i, j in d[e]:
                union(i,m+j)
            for i, j in d[e]:
                rank[i] = rank[m+j] = matrix[i][j] = newrank[find(i)] + 1
        return matrix