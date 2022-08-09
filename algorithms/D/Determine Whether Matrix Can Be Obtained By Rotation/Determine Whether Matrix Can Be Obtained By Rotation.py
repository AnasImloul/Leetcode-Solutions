class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        
        # if already equal
        if target == mat:
            return True
        # there are 4 different rotation with 90 deg. 
        # We need to check at most 3 more rotation.
        for i in range(3):
            # transpose the matrix by swap row and col values.
            for j in range(len(mat)):
                for k in range(j+1, len(mat)):
                    mat[j][k], mat[k][j] = mat[k][j], mat[j][k]
                # Reflect the row by reverse it.
                mat[j] = mat[j][::-1]
            # now the matrix is roteted; check if they're alike.
            if target == mat:
                return True
        return False
