# Runtime: 61 ms (Top 26.67%) | Memory: 13.9 MB (Top 37.41%)
class Solution(object):
    def generateMatrix(self, n):
        if n==1:
            return [[1]]
        matrix=[[0 for a in range(n)] for b in range(n)]
        le_b=0
        u_b=0
        r_b=n-1
        lo_b=n-1
        ele=1
        while ele<(n**2)+1:
            i=u_b
            j=le_b
            while ele<(n**2)+1 and j<=r_b:
                matrix[i][j]=ele
                ele+=1
                j+=1
            u_b+=1
            i=u_b
            j=r_b
            while ele<(n**2)+1 and i<=lo_b:
                matrix[i][j]=ele
                ele+=1
                i+=1
            r_b-=1
            i=lo_b
            j=r_b
            while ele<(n**2)+1 and j>=le_b:
                matrix[i][j]=ele
                ele+=1
                j-=1
            lo_b-=1
            i=lo_b
            j=le_b
            while ele<(n**2)+1 and i>=u_b:
                matrix[i][j]=ele
                ele+=1
                i-=1
            le_b+=1
        return matrix
        ```