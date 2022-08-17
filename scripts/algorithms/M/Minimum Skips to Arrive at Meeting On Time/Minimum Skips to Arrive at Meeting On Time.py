from math import *
class Solution:
    def minSkips(self, dist: List[int], speed: int, hoursBefore: int) -> int:
        n=len(dist)
		# Error Range 10^-9 can be ignored in ceil, so we will subtract this value before taking ceil 
        e=1e-9
        mat=[[0 for i in range(n)]for j in range(n)]
        mat[0][0]=dist[0]/speed
		# Initialization 
		# Values where 0 skips are considered
        for i in range(1,n):
            mat[i][0]=ceil(mat[i-1][0]-e)+dist[i]/speed
        for i in range(1,n):
            for j in range(1,i):
                mat[i][j]=min(ceil(mat[i-1][j]-e),mat[i-1][j-1])+dist[i]/speed
            mat[i][i]=mat[i-1][i-1]+dist[i]/speed
        for i in range(n):
            if mat[-1][i]<=hoursBefore:
                return i
        return -1
