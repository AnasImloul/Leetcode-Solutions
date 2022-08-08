class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        res, N = [], len(pattern)
		
        for query in queries:
		
            if self.upLetter(query) != self.upLetter(pattern) or self.LCS(query, pattern) != N:
                res.append(False)
            
            else:
                res.append(True)
				
        return res
                
        
		
    def LCS(self, A, B):
        N, M = len(A), len(B)
        d = [[0 for _ in range(M+1)] for _ in range(N+1)]

        for i in range(1, N+1):
            for j in range(1, M+1):
			
                if A[i - 1] == B[j - 1]:
                    d[i][j] = 1 + d[i-1][j-1]

                else:
                    d[i][j] = max(d[i-1][j], d[i][j-1])
        return d[-1][-1]


    
    def upLetter(self, w):
        count = 0
        for c in w:
            if c.isupper():
                count += 1
        return count

