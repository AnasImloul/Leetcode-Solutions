# Runtime: 7285 ms (Top 5.13%) | Memory: 29.8 MB (Top 5.13%)
from collections import defaultdict

class Solution:
    def hitBricks(self, grid: List[List[int]], hits: List[List[int]]) -> List[int]:
        parent = defaultdict()
        sz = defaultdict(lambda:1)
        empty = set()
        def find(i):
            if parent[i] != i:
                parent[i] = find(parent[i])
            return parent[i]
        def union(i,j):
            pi = find(i)
            pj = find(j)
            if pi != pj:
                parent[pi] = pj
                sz[pj] += sz[pi]
        row = len(grid)
        col = len(grid[0])
        for r in range(row):
            for c in range(col):
                parent[(r,c)] = (r,c)
        parent[(row,col)] = (row,col)
        for r, c in hits:
            if grid[r][c]:
                grid[r][c] = 0
            else:
                empty.add((r,c))
        for r in range(row):
            for c in range(col):
                if not grid[r][c]:
                    continue
                for dr, dc in [[-1,0],[1,0],[0,1],[0,-1]]:
                    if 0 <= r + dr < row and 0 <= c + dc < col and grid[r+dr][c+dc]:
                        union((r, c),(r+dr, c+dc))
                if r == 0:
                    union((r,c),(row,col))
        res = [0]*len(hits)
        for i in range(len(hits)-1,-1,-1):
            r, c = hits[i]
            if (r,c) in empty:
                continue
            grid[r][c] = 1
            curbricks = sz[find((row,col))]
            for dr, dc in [[-1,0],[1,0],[0,1],[0,-1]]:
                if 0 <= r + dr < row and 0 <= c + dc < col and grid[r+dr][c+dc]:
                    union((r,c),(r+dr,c+dc))
            if r == 0:
                union((r,c),(row,col))
            nextbricks = sz[find((row,col))]
            if nextbricks > curbricks:
                res[i] = nextbricks - curbricks - 1
        return res