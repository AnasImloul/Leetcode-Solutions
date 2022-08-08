class Solution:
    def transpose(self, matrix: List[List[int]]) -> List[List[int]]:
        rows=len(matrix)
        cols=len(matrix[0])
        ans=[[0]*rows]*cols
        for i in range(cols):
            for j in range(rows):
                ans[i][j]=matrix[j][i]
        return ans
