class Solution:
    def minimumMoves(self, grid: List[List[int]]) -> int:
        queue , vis , n = [(0,1,0,0)] , {} , len(grid)
        while queue:
            x,y,pos,moves = queue.pop(0)
            if x == y == n-1 and pos == 0: return moves
            if pos == 0:
                if y + 1 < n and grid[x][y+1] == 0 and (x,y+1,0) not in vis:
                    vis[(x,y+1,0)] = True
                    queue.append((x,y+1,0,moves+1))
                
                if x + 1 < n and grid[x+1][y-1] == 0 and grid[x+1][y] == 0:
                    if (x+1,y-1,1) not in vis:
                        vis[(x+1,y-1,1)] = True
                        queue.append((x+1,y-1,1,moves+1))
                    if (x+1,y,0) not in vis:
                        vis[(x+1,y,0)] = True
                        queue.append((x+1,y,0,moves+1))
            else:
                if x + 1 < n and grid[x+1][y] == 0 and (x+1,y,1) not in vis:
                    vis[(x+1,y,1)] = True
                    queue.append((x+1,y,1,moves+1))
                if y + 1 < n and grid[x-1][y+1] == grid[x][y+1] == 0:
                    if (x-1,y+1,0) not in vis:
                        vis[(x-1,y+1,0)] = True
                        queue.append((x-1,y+1,0,moves+1))
                    if (x,y+1,1) not in vis:
                        vis[(x,y+1,1)] = True
                        queue.append((x,y+1,1,moves+1))
        return -1
