# Runtime: 2311 ms (Top 90.13%) | Memory: 73.8 MB (Top 86.18%)
'''
* Make groups of nodes which are connected
    eg., edges = [[0,2],[0,5],[2,4],[1,6],[5,4]]

    0 ---- 2 1 --- 6 3
    | |
    | |
    5 ---- 4

    groups will be {0: 4, 1: 2, 3: 1},
    i.e 4 nodes are present in group0, 2 nodes are present in group1 and 1 node is present in group3

* Now, we have [4, 2, 1] as no of nodes in each group, we have to multiply each of no. with remaining
    ans = (4 * 2 + 4 * 1) + (2 * 1)
    but calculating ans this way will give TLE.

* if we notice, (4 * 2 + 4 * 1) + (2 * 1), we can combine, equation like this,
    4 * 2 + (4 + 2) * 1, using this, we can reduce complexity.
    so, if we have count of groups array as [a, b, c, d], ans will be,
    ans = a * b + (a + b) * c + (a + b + c) * d

* will use, union for generating groups.
* ps, you can modify UnionFind class as per your need. Have implemented full union-find for beginners.
'''

class UnionFind:
    def __init__(self, size):
        self.root = [i for i in range(size)]
        self.rank = [1] * size
    def find(self, x):
        if x == self.root[x]:
            return x
        self.root[x] = self.find(self.root[x])
        return self.root[x]
    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.root[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.root[rootX] = rootY
            else:
                self.root[rootY] = rootX
                self.rank[rootX] += 1

class Solution:
    def countPairs(self, n: int, edges: List[List[int]]) -> int:
        dsu = UnionFind(n)
        for u, v in edges:
            dsu.union(u, v)
        C = Counter([dsu.find(i) for i in range(n)])
        groupCounts = list(C.values())
        ans = 0
        firstGroupCount = groupCounts[0]
        for i in range(1, len(groupCounts)):
            ans += firstGroupCount * groupCounts[i]
            firstGroupCount += groupCounts[i]
        return ans