# Runtime: 472 ms (Top 12.37%) | Memory: 14 MB (Top 32.41%)
class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        n = len(arr)
        d = {}
        def findMax(start,end):
            if (start,end) in d: return d[(start,end)]
            maxx = start
            for i in range(start+1,end+1):
                if arr[maxx] < arr[i] : maxx = i
            d[(start,end)] = arr[maxx]
            return arr[maxx]

        dp = [[float('inf') for i in range(n)] for j in range(n)]
        for gap in range(n):
            for row in range(n - gap):
                col = row + gap
                if gap == 0:
                    dp[row][col] = 0
                elif gap == 1:
                    dp[row][col] = arr[row] * arr[col]
                else:
                    for k in range(row,col):
                        val = dp[row][k] + findMax(row,k) * findMax(k+1,col) + dp[k+1][col]
                        if val < dp[row][col]: dp[row][col] = val

        return dp[0][-1]
