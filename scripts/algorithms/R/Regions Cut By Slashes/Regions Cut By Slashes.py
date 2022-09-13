# Runtime: 124 ms (Top 90.60%) | Memory: 14.5 MB (Top 61.93%)
class Solution:
    def regionsBySlashes(self, grid: List[str]) -> int:
        n=len(grid)
        dots=n+1
        par=[0]*(dots*dots)
        rank=[0]*(dots*dots)
        self.count=1

        def find(x):
            if par[x]==x:
                return x
            temp=find(par[x])
            par[x]=temp
            return temp
        def union(x,y):
            lx=find(x)
            ly=find(y)
            if lx!=ly:
                if rank[lx]>rank[ly]:
                    par[ly]=lx
                elif rank[lx]<rank[ly]:
                    par[lx]=ly
                else:
                    par[lx]=ly
                    rank[ly]+=1
            else:
                self.count+=1
    #-------------------------------------------#
        for i in range(len(par)):
            par[i]=i
            rank[i]=1
        for i in range(dots):
            for j in range(dots):
                if i==0 or j==0 or i==dots-1 or j==dots-1:
                    cellno=i*dots+j
                    if cellno!=0:
                        union(0,cellno)
        for i in range(len(grid)):
            ch=grid[i]
            for j in range(len(ch)):
                if ch[j]=='/':
                    cellno1=i*dots+j+1
                    cellno2=(i+1)*dots+j

                    union(cellno1,cellno2)
                elif ch[j]=='\\':
                    cellno1=i*dots+j
                    cellno2=(i+1)*dots+j+1
                    union(cellno1,cellno2)
        return self.count