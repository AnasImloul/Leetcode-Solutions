# Runtime: 1480 ms (Top 97.21%) | Memory: 14.1 MB (Top 13.08%)
class Solution:
    def getMaximumGold(self, grid):
        answer = [0]

        def visit(visited, i, j, gold_sum):
            val = grid[i][j]
            if val == 0 or (i,j) in visited:
                answer[0] = max(answer[0], gold_sum)
                return

            gold_sum_new = gold_sum + val
            visited_new = visited.union({(i,j)})

            if i > 0:
                visit(visited_new, i-1, j, gold_sum_new)

            if j < len(grid[i]) - 1:
                visit(visited_new, i, j+1, gold_sum_new)

            if i < len(grid) - 1:
                visit(visited_new, i+1, j, gold_sum_new)
            if j > 0:
                visit(visited_new, i, j-1, gold_sum_new)
        #choosing the starting points
        for i in range(len(grid)):
            for j in range(len(grid[i])):
                if grid[i][j] != 0:
                    count = 0

                    try:
                        if grid[i-1][j] != 0:
                            count += 1
                    except:
                        pass
                    try:
                        if grid[i][j+1] != 0:
                            count += 1
                    except:
                        pass
                    try:
                        if grid[i+1][j] != 0:
                            count += 1
                    except:
                        pass
                    try:
                        if grid[i][j-1] != 0:
                            count += 1
                    except:
                        pass

                    if count < 3:
                        visit(set(),i,j,0)

        return answer[0]
