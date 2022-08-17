class UF:
    def __init__(self, m, n):
        self.n, self.loc_id, c_id = n, dict(), 0
        self.col_set = [set() for _ in range(m*n)]
        for i in range(m):                       # Assign id for each location (i ,j)
            for j in range(n):
                self.loc_id[(i, j)] = c_id
                self.col_set[c_id].add(j)
                c_id += 1
        self.p = [i for i in range(m*n)]         # Initialize parents array `p`
        
    def find(self, i):
        if self.p[i] != i:
            self.p[i] = self.find(self.p[i])
        return self.p[i]    
    
    def union(self, i, j):
        pi, pj = self.find(i), self.find(j)
        if pi != pj:
            self.p[pj] = pi                      # Update `pi`
            self.col_set[pi] = self.col_set[pi] | self.col_set[pj]  # Take union of two sets (union all occupied columns)
        return len(self.col_set[pi]) == self.n   # if length of col_set[pi] == self.n, meaning this piece occupied all columns from 1 to `col` inclusive, meaning we are blocked
            
class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        uf, visited = UF(row, col), set()
        for i, (x, y) in enumerate(cells):
            x, y = x-1, y-1
            visited.add((x, y))
            for dx, dy in [(-1, -1), (-1, 0), (-1, 1), (1, -1), (1, 0), (1, 1), (0, 1), (0, -1)]:
                _x, _y = x+dx, y+dy              # Check if neighbor is flooded
                if 0 <= _x < row and 0 <= _y < col and (_x, _y) in visited:
                    id1, id2 = uf.loc_id[(_x, _y)], uf.loc_id[(x, y)]
                    if uf.union(id1, id2): return i # Union two flooded piece and return index if union return True
        return -1
