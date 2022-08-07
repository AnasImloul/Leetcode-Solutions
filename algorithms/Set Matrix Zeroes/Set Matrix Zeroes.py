class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        rows = len(matrix)
        cols = len(matrix[0])
        visited=set()
        for r in range(rows):
            for c in range(cols):
                
                if matrix[r][c]==0 and (r,c) not in visited :
                    for t in range(cols):
                        if matrix[r][t]!=0:
                            matrix[r][t]=0
                            visited.add((r,t))
                    for h in range(rows):
                        if matrix[h][c]!=0:
                            matrix[h][c]=0
                            visited.add((h,c))
        ##Time Complexity :- O(m*n)
        ##Space Complexity:- O(m+n)
		
		```