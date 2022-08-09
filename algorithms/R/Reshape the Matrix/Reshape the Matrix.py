class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        if m*n != r*c:
            return mat
        
        temp = [mat[i][j] for i in range(m) for j in range(n)]
        ans = [[0]*c]*r
        print(ans)
        for i in range(r):
            for j in range(c):
                ans[i][j] = temp[i*c + j]
                print(ans)
        return ans
