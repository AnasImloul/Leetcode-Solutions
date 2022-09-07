# Runtime: 3643 ms (Top 25.24%) | Memory: 14.1 MB (Top 78.64%)
class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:

        def isMagicSquare(i, j, length):
            s = set()

            #for all rows
            for x in range(length):
                sum = 0
                for y in range(length):
                    sum += grid[i+x][j+y]
                s.add(sum)
                if len(s)>1:
                    return False

            #for all cols
            for y in range(length):
                sum = 0
                for x in range(length):
                    sum += grid[i+x][j+y]
                s.add(sum)
                if len(s)>1:
                    return False

            # for forward diagonal
            sum = 0
            for x in range(length):
                sum += grid[i+x][j+x]
            s.add(sum)
            if len(s)>1:
                return False

            #for backward diagonal
            sum = 0
            for x in range(length):
                sum += grid[i+x][j+ length - 1 - x]
            s.add(sum)
            if len(s)>1:
                return False
            return True

        n = len(grid)
        m = len(grid[0])

        l = min(n,m)

        for k in range(l, 1, -1):
            for i in range(n-k+1):
                for j in range(m-k+1):
                    if isMagicSquare(i, j, k):
                        return k
        return 1