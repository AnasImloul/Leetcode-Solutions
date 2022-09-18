# Runtime: 6408 ms (Top 13.33%) | Memory: 26.1 MB (Top 43.33%)
from collections import defaultdict
from itertools import accumulate

class Solution:

    def stoneGameV(self, stoneValue: List[int]) -> int:
        n = len(stoneValue)
        dp = [[0]*n for _ in range(n)]
        left = [[0]*n for _ in range(n)]
        prefix = list(accumulate(stoneValue))
        prefix = [0]+prefix+[prefix[-1]]

        def sum(i,j):
            return prefix[j+1]-prefix[i]

        row_idx = [i for i in range(n)]
        for i in range(n):
            left[i][i] = stoneValue[i]
        for d in range(1,n):
            for i in range(n-d):
                j = i+d
                while sum(i,row_idx[i]) < sum(row_idx[i]+1,j):
                    row_idx[i] +=1
                if sum(i, row_idx[i]) == sum(row_idx[i]+1,j):
                    dp[i][j] = max(left[i][row_idx[i]], left[j][row_idx[i]+1])
                else:
                    if row_idx[i] == i:
                        dp[i][j] = left[j][i+1]
                    elif row_idx[i] == j:
                        dp[i][j] = left[i][j-1]
                    else:
                        dp[i][j] = max(left[i][row_idx[i]-1], left[j][row_idx[i]+1])
                left[j][i] = max(left[j][i+1],sum(i,j)+dp[i][j])
                left[i][j] = max(left[i][j-1],sum(i,j)+dp[i][j])
        return dp[0][n-1]