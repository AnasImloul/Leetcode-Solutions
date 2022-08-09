class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        flag, rowNum, colNum = True, len(mat), len(mat[0])

        total, ans = 0, []
        while total <= rowNum + colNum - 2:
            iLimited = rowNum - 1 if flag else colNum - 1 
            jLimited = colNum - 1 if flag else rowNum - 1
            i = total if total < iLimited else iLimited
            j = total - i
            while i >= 0 and j <= jLimited:
                if flag:
                    ans.append(mat[i][j])
                else:
                    ans.append(mat[j][i])
                i -= 1
                j += 1
            total += 1
            flag = not flag
        return ans
