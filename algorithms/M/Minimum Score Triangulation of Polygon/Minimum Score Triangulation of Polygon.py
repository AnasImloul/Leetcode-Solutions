class Solution:
    def minScoreTriangulation(self, values: List[int]) -> int:
        
        n = len(values)
        
        c = [[0 for _ in range(n)] for _ in range(n)]
        
        for L in range(2, n):
            
            for i in range(1, n-L+1):
                
                j = i + L - 1
                
                c[i][j] = float('inf')
                
                for k in range(i, j):
                    
                    q = c[i][k] + c[k+1][j] + (values[i-1]*values[k]*values[j])
                    
                    if c[i][j] > q:
                        c[i][j] = q
        
        return c[1][n-1]
                
                
        
            
        
