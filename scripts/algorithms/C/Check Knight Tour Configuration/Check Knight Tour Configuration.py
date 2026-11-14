# Runtime: 2 ms (Top 38.14%) | Memory: 19.20 MB (Top 83.72%)

class Solution:
    def checkValidGrid(self, grid: List[List[int]]) -> bool:

        n, d = len(grid), defaultdict(tuple)
        if n < 5: return n == 1

        notLegal = lambda x, y : {abs(x[0]-y[0]),
                                  abs(x[1]-y[1])} != {1,2}

        for row, col in product(range(n),range(n)):
            d[grid[row][col]] = (row,col)

        prev, cnt = (0,0), 1

        while cnt < n*n:
            curr = d[cnt]

            if notLegal(prev,curr):  return False

            cnt+=1
            prev = curr

        return True
