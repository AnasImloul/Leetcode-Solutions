# Runtime: 187 ms (Top 84.32%) | Memory: 18.9 MB (Top 5.06%)
class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        def dfs(row,col):
            if seen[(row,col)]:
                return 0
            seen[(row,col)] = True
            for r,c in tableRow[row]:
                dfs(r,c)
            for r,c in tableCol[col]:
                dfs(r,c)
            return 1

        tableRow, tableCol = {},{}
        for row,col in stones:
            if row not in tableRow:
                tableRow[row] = set()
            if col not in tableCol:
                tableCol[col] = set()
            tableRow[row].add((row,col))
            tableCol[col].add((row,col))

        count,seen= 0, {(row,col):False for row,col in stones}
        for row,col in stones:
            count += dfs(row,col)
        return abs(len(stones)-count)