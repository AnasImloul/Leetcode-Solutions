# Runtime: 145 ms (Top 31.88%) | Memory: 42.00 MB (Top 94.93%)

class Solution:
    def constructProductMatrix(self, grid: List[List[int]]) -> List[List[int]]:

        m,n = len(grid), len(grid[0])

        prefix, suffix = [1], [1]

        for i in range(m):
            for j in range(n):
                prefix.append((prefix[-1] * grid[i][j]) % 12345)

        for i in reversed(range(m)):
            for j in reversed(range(n)):
                suffix.append((suffix[-1] * grid[i][j]) % 12345)

        for i,j in product(range(m), range(n)):
            k = i * n + j
            grid[i][j] = (prefix[k] * suffix[-k-2]) % 12345

        return grid
