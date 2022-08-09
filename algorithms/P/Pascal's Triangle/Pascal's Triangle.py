class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1, 1]]
        ans = [[1], [1, 1]]
        for x in range(1, numRows - 1):
            tmp = [1]
            for k in range(len(ans[x]) - 1):
                tmp.append(ans[x][k] + ans[x][k + 1])
            tmp.append(1)
            ans.append(tmp)
        return ans
