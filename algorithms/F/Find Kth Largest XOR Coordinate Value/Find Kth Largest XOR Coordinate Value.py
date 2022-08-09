class Solution:
    def kthLargestValue(self, matrix: List[List[int]], k: int) -> int:
        temp=0
        pq= []
        n = len(matrix)
        m = len(matrix[0])
        
        prefix= [  [0]*m for i in range(n) ]
        
        
        for i in range(n):
            for j in range(m):
                if i==0 or j==0:
                    if i==0 and j==0:
                        prefix[i][j] = matrix[i][j]
                    elif i==0 and j!=0:
                        prefix[i][j] ^= prefix[i][j-1]^ matrix[i][j]
                    else:
                        prefix[i][j]^=prefix[i-1][j]^ matrix[i][j]
                else:
                    
                    prefix[i][j] ^= prefix[i-1][j] ^ prefix[i][j-1]^matrix[i][j]^prefix[i-1][j-1]
                if len(pq)<k:
                    heappush(pq,prefix[i][j])    
                else:
                    heappush(pq, prefix[i][j])
                    heappop(pq)
                

                  
        return heappop(pq)
                    
