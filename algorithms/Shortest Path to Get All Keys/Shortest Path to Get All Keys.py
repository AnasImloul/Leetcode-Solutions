class Solution:
    def shortestPathAllKeys(self, grid: List[str]) -> int:
        
        m=len(grid)
        n=len(grid[0])
        visited=set()
        
        steps=0
        q=deque([])
        keyCt=0
        
        for i in range(m):
            for j in range(n):
                if grid[i][j]=="@":
                    q.append((i,j,''))
                elif grid[i][j].islower():
                    keyCt+=1
        
        while q:
            for _ in range(len(q)):
                curr_x,curr_y,keys = q.popleft()
                if (curr_x,curr_y,keys) in visited:
                    continue
                
                visited.add((curr_x,curr_y,keys))
                
                if len(keys)==keyCt:
                    return steps
                
                for x,y in ((0,1),(1,0),(-1,0),(0,-1)):
                    nx=curr_x+x
                    ny=curr_y+y
                    if nx<0 or ny<0 or nx>=m or ny>=n or grid[nx][ny]=='#' or (nx,ny,keys) in visited:
                        continue
                        
                    curr=grid[nx][ny]                    
                    if curr in 'abcdef' and curr not in keys:
                        q.append((nx,ny,keys+curr))                            
                    elif curr.isupper() and curr.lower() not in keys:
                        continue
                    else:
                        q.append((nx,ny,keys))
            steps+=1
        
        return -1