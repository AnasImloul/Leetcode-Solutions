class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # parent array to keey track
        parent = list(range(m*n))
        # rank array used for union by rank and size calculation
        rank = [1 for _ in range(m*n)]
        
        # standard DSU find function
        def find(x):
            while x != parent[x]:
                parent[x] = parent[parent[x]]
                x = parent[x]
            return x
        
        # standard DSU union by rank function
        def union(x,y):
            parX, parY = find(x), find(y)
            if parX == parY: return
            if rank[parX] >= rank[parY]:
                rank[parX] += rank[parY]
                parent[parY] = parX
            else:
                rank[parY] += rank[parX]
                parent[parX] = parY
    
        # Step 1: join the land

        # for each island we perform union operation
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                
                # important condition: if we have a water body, we set its rank to 0 (will be used in the next step)
                if not val: 
                    rank[i*m+j] = 0
                    continue
                
                # performing union of land bodies
                for x,y in [(i-1, j),(i+1, j),(i, j+1),(i, j-1)]:
                    # outside of grid check
                    if not (0 <= x < m and 0 <= y < n): continue
                    
                    if grid[x][y]: union(i*m+j, x*m+y)
        
        # Step 2: convert a water body (if present)
        
        # the minimum final ans will always be the size of the largest land present 
        ans = max(rank)
        for i, row in enumerate(grid):
            for j, val in enumerate(row):
                
                # we dont need to do anything if we encounter a land
                if val: continue
                
                neighbours = set()
                res = 0
                
                # 
                for x,y in [(i-1, j),(i+1, j),(i, j+1),(i, j-1)]:
                    # outside of grid check
                    if not (0 <= x < m and 0 <= y < n): continue
                        
                    # checking unique neighbours by adding the parent to the set
                    # here we dont care if the neighbour is water as its rank is 0 so it contributes nothing
                    idx = x*m+y
                    neighbours.add(find(idx))
                
                # Once we have all unique neighbours, just add their ranks
                for idx in neighbours:
                    res += rank[idx]
                
                # res + 1 because we convert the current cell (i,j) to land too
                ans = max(ans, res+1)
        
        return ans
