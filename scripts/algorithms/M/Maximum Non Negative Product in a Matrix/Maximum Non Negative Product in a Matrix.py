# Runtime: 124 ms (Top 34.73%) | Memory: 14.1 MB (Top 52.30%)
class Solution(object):
    def maxProductPath(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        MOD = 1e9+7
        row = len(grid)
        col = len(grid[0])

        # Make a dp that contains [max, min]
        dp = [[0 for _ in range(col)] for _ in range(row)]

        for i in range(row):
            for j in range(col):
                if i == 0 and j == 0:
                    dp[i][j] = [grid[i][j], grid[i][j]]

                elif i == 0:
                    ans1 = dp[i][j-1][0] * grid[i][j]
                    dp[i][j] = [ans1, ans1]

                elif j == 0:
                    ans1 = dp[i-1][j][0] * grid[i][j]
                    dp[i][j] = [ans1, ans1]

                else:
                    # Find all the combination of multiplication.
                    # For example if grid[i][j] < 0 i.e -2 and dp[i-1][j] = [2,-2] and dp[i][j-1] = [1,2]
                    # then dp[i][j] = [max(-2*2, -2*-2, -2*1, -2*2), min(-2*2, -2*-2, -2*1, -2*2)]
                    # Only one thing you have to focus here is that if the multiplication is negative you have to store it because
                    # it may happen that if we find a negative number later on that can make a big positve number.

                    ans1 = dp[i-1][j][0] * grid[i][j]
                    ans2 = dp[i-1][j][1] * grid[i][j]
                    ans3 = dp[i][j-1][0] * grid[i][j]
                    ans4 = dp[i][j-1][1] * grid[i][j]
                    maximum = max(ans1, ans2, ans3, ans4)
                    minimum = min(ans1, ans2, ans3 ,ans4)
                    if maximum < 0:
                        dp[i][j] = [minimum, minimum]
                    elif minimum > 0 :
                        dp[i][j] = [maximum, maximum]
                    else:
                        dp[i][j] = [maximum, minimum]

        if dp[row-1][col-1][0] < 0:
            return -1
        else:
            return int(dp[row-1][col-1][0] % MOD)
