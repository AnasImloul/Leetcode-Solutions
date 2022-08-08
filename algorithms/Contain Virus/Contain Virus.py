 class Solution:
    def containVirus(self, mat: List[List[int]]) -> int:
        m,n = len(mat),len(mat[0])

        def dfs(i,j,visited,nextInfected):  # return no. of walls require to quarantined dfs area
            if 0<=i<m and 0<=j<n and (i,j) not in visited:
                if mat[i][j]==2: # Already quarantined cell
                    return 0
                if mat[i][j]==0:
                    nextInfected.add((i,j)) # add cell which will be infected next day
                    return 1   # require one wall to quarantined cell from one side
                    
                else:
                    visited.add((i,j))
                    return dfs(i-1,j,visited,nextInfected) + dfs(i+1,j,visited,nextInfected) + dfs(i,j-1,visited,nextInfected) + dfs(i,j+1,visited,nextInfected)  # traverse all four direction
            else:
                return 0
				
        ans = 0 
        while True:   # this loop running "how many days we should installing the walls" times
            # For every day check which area infect more cells
            visited = set()  # Using in dfs
            All_nextinfect  = set()
            stop , walls = set(),0   # here stop store the indices of maximum no. of cells in which we stop spreading of virus this day
            
            for i in range(m):
                for j in range(n):
                    if mat[i][j]==1 and (i,j) not in visited:
                        nextInfected = set()
                        a = dfs(i,j,visited,nextInfected)
                        
                        if len(stop)<len(nextInfected):
                            All_nextinfect  = All_nextinfect | stop # leave previous saved area from virus
                            stop = nextInfected  # pick new area which we want to save
                            walls = a  # require walls
                            p,q = i,j  # starting position(indices) of this area
                        else:
                            All_nextinfect  = All_nextinfect | nextInfected   
                            
            if not stop : # if our job is done i.e. No cell will be infect Later
                break
            ans += walls  # add new walls installed this day
            
            # change each cell value to 2 which will be covered by quarantined area
            def fun(p,q):
                if 0<=p<m and 0<=q<n and mat[p][q]==1:
                    mat[p][q]=2
                    fun(p+1,q)
                    fun(p-1,q)
                    fun(p,q-1)
                    fun(p,q+1)
            fun(p,q) # start dfs from start point of quarantined area
            
            for a,b in All_nextinfect: # set new infected cell value = 1 for iterating next day
                mat[a][b] = 1

        return ans   # Final answer 
