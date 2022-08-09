class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        m,n=len(grid),len(grid[0])
        q=deque()
        start,target,box=(0,0),(0,0),(0,0)
        for i in range(m):
            for j in range(n):
                if grid[i][j]=="B":
                    box=(i,j)
                elif grid[i][j]=="T":
                    target=(i,j)
                elif grid[i][j]=="S":
                    start=(i,j)
        q.append((box[0],box[1],0,start[0],start[1]))
        visited=set()
        directions=((1,0,-1,0),(0,1,0,-1),(-1,0,1,0),(0,-1,0,1))
        visited.add(box+box)
        def solve(i,j,bi,bj):
            nonlocal seen
            if (i,j)==(bi,bj):
                return True
            ans=False
            for d in directions:
                ni,nj=i+d[0],j+d[1]
                if 0<=ni<m and 0<=nj<n and (ni,nj) not in seen and grid[ni][nj]!="#":
                    seen.add((ni,nj))
                    ans=ans or solve(ni,nj,bi,bj)
                    if ans: return ans
            return ans
        while q:
            i,j,pushes,si,sj=q.popleft()
            if (i,j)==target:
                return pushes
            if pushes>m+n:
                return -1
            for d in directions:
                ni,nj,bi,bj=i+d[0],j+d[1],i+d[2],j+d[3]
                if 0<=ni<m and 0<=nj<n and (ni,nj,i,j) not in visited and grid[ni][nj]!="#" and 0<=bi<m and 0<=bj<n and grid[bi][bj]!="#":
                    seen=set()
                    seen.add((i,j))
                    grid[i][j]=="#"
                    res=solve(si,sj,bi,bj)
                    grid[i][j]="."
                    if not res:
                        continue
                    visited.add((ni,nj,i,j))
                    q.append((ni,nj,pushes+1,i,j))
        return -1
