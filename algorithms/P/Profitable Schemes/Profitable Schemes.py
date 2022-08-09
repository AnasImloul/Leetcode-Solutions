class Solution:
    def profitableSchemes(self, n, minProfit, group, profit):
        
        k = len(group)
        arr = [[[0 for _ in range(k+1)] for _ in range(minProfit+1)] for _ in range(n+1)]
        
        for i in range(n+1):
            arr[i][0][k] = 1
       
        for j in range(k-1,-1,-1):
            for i in range(n,-1,-1):
                for x in range(minProfit,-1,-1):

                    arr[i][x][j] = arr[i][x][j+1]
                    if i>=group[j]:
                        arr[i][x][j] += arr[i-group[j]][max(x-profit[j],0)][j+1]
        
        return arr[n][minProfit][0] % (10**9 + 7)

