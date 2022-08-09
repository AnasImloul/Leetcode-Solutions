class Solution:
    def hasValidPath(self, grid: List[List[int]]) -> bool:
        r,c=len(grid),len(grid[0])
        dic={
            2:[(-1,0),(1,0)],
            1:[(0,1),(0,-1)],
            5:[(-1,0),(0,-1)],
            3:[(1,0),(0,-1)],
            6:[(0,1),(-1,0)],
            4:[(0,1),(1,0)]
            
        }
        q=collections.deque([(0,0)])
        visit=set()
        while q:
            i,j=q.popleft()
            visit.add((i,j))
            if i==r-1 and j==c-1:
                return True
            for x,y in dic[grid[i][j]]:
                nx=i+x
                ny=j+y
                if nx>=0 and nx<r and ny>=0 and ny<c and (nx,ny) not in visit:
                    if (-x,-y) in dic[grid[nx][ny]]:
                        q.append((nx,ny))
        return False
