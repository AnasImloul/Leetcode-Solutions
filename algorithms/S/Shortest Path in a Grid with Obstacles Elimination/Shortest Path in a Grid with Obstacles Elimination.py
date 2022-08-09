class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        Q = [[0, 0, k]] # m, n, remaining elimination quota 
        rows, cols = len(grid), len(grid[0])
        V, counter = {(0, 0):k}, 0 # I use a V to keep track of how cells have been visited
        
        while Q: 
            frontier = []
            for m, n, rem in Q: 
                if m == rows - 1 and n == cols - 1: 
                    return counter 
                for dm, dn in [[1, 0], [-1, 0], [0, 1], [0, -1]]: 
                    if 0 <= m+dm < rows and 0 <= n+dn < cols: # check inbound 
                        if grid[m+dm][n+dn] == 0: 
                            if (m+dm, n+dn) not in V or V[(m+dm, n+dn)] < rem: # if not visited or could be visited with fewer elimination 
                                frontier.append([m+dm, n+dn, rem])
                                V[(m+dm, n+dn)] = rem
                        elif rem > 0: # I see a wall and I can still eliminate
                            if (m+dm, n+dn) not in V or V[(m+dm, n+dn)] < rem - 1: # if not visited or could be visited with fewer elimination 
                                frontier.append([m+dm, n+dn, rem-1])
                                V[(m+dm, n+dn)] = rem - 1
            Q = frontier 
            counter += 1
                
        return -1
	```