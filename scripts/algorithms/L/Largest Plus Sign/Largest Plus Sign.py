class Solution:

    def orderOfLargestPlusSign(self, n: int, mines: list[list[int]]) -> int:
        matrix = [1] * n
        aux = {}
        hasOne = False
        for i in range(0,n):
            matrix[i] = [1] * n
        for mine in mines:
            matrix[mine[0]][mine[1]] = 0
        for i in range(0,n):
            for j in range(0,n):
                if(matrix[i][j] == 1):
                    hasOne = True
                if((i,j) not in aux):
                    aux[(i,j)] = {"t":0,"l":0,"r":0,"b":0}
                if(j>0 and matrix[i][j] == 1 and matrix[i][j-1] == 1):
                    aux[(i,j)]["l"] = aux[(i,j-1)]["l"] + 1  
                if(i>0 and matrix[i][j] == 1 and matrix[i-1][j] == 1):
                    aux[(i,j)]["t"] = aux[(i-1,j)]["t"] + 1
        
        maxOrder = 0 
        for i in range(n-1,-1,-1):
            if(i<maxOrder):
                    break
            for j in range(n-1,-1,-1):
                if(j<maxOrder):
                    break
                if(j<n-1 and matrix[i][j] == 1 and matrix[i][j+1] == 1):
                    aux[(i,j)]["r"] = aux[(i,j+1)]["r"] + 1  
                if(i<n-1 and matrix[i][j] == 1 and matrix[i+1][j]):
                    aux[(i,j)]["b"] = aux[(i+1,j)]["b"] + 1
                maxOrder = max(min(aux[(i,j)]["b"],aux[(i,j)]["t"],aux[(i,j)]["r"],aux[(i,j)]["l"]),maxOrder)
 
        print(maxOrder+1)
        return maxOrder + 1 
