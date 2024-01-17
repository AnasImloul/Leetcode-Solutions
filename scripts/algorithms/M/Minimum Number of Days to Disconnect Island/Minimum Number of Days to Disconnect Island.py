// Runtime: 70 ms (Top 98.46%) | Memory: 18.30 MB (Top 33.85%)

class Solution:
    def minDays(self, grid: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])

        disc_time = [[-1 for _ in range(cols)] for _ in range(rows)]
        low_value = [[-1 for _ in range(cols)] for _ in range(rows)]
        parents = [[(-1, -1) for _ in range(cols)] for _ in range(rows)]
        is_ap = [[False for _ in range(cols)] for _ in range(rows)]
        dirs = [(1, 0), (0, 1), (-1, 0), (0, -1)]

        time = 0
        has_ap = False
        def dfs(i, j):
            if grid[i][j] == 0:
                return
            nonlocal time
            nonlocal has_ap
            disc_time[i][j] = time
            low_value[i][j] = time
            time += 1

            child = 0
            for di, dj in dirs:
                ni, nj = i + di, j + dj
                if not (0 <= ni < rows) or not (0 <= nj < cols):
                    continue
                if grid[ni][nj] != 1:
                    continue

                if disc_time[ni][nj] == -1: # not visited
                    child += 1
                    parents[ni][nj] = (i, j)
                    dfs(ni, nj)
                    low_value[i][j] = min(low_value[i][j], low_value[ni][nj])

                    if parents[i][j] == (-1, -1) and child > 1:
                        is_ap[i][j] = True
                        has_ap = True

                    if parents[i][j] != (-1, -1) and low_value[ni][nj] >= disc_time[i][j]:
                        is_ap[i][j] = True
                        has_ap = True
                elif (ni, nj) != parents[i][j]:
                    low_value[i][j] = min(low_value[i][j], disc_time[ni][nj])

        sccs = 0
        num_ones = 0
        for i in range(rows):
            for j in range(cols):
                if grid[i][j] == 1:
                    num_ones += 1
                if disc_time[i][j] == -1 and grid[i][j] == 1:
                    dfs(i, j)
                    sccs += 1


        if sccs > 1:
            return 0
        elif has_ap:
            return 1
        else:
            if num_ones == 1:
                return 1
            elif num_ones == 0:
                return 0
        return 2


