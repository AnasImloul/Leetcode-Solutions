class Solution:
    def minimumTotal(self, t: List[List[int]]) -> int:
        dp = []
        dp.append(t[0])
        
        r = len(t)
        answer = float('inf')
        for i in range(1, r):
            c = len(t[i])
            dp.append([])
            for j in range(0, c):
                if j == 0:
                    val = dp[i - 1][j] + t[i][j]
                elif j == c - 1:
                    val = dp[i - 1][j - 1] + t[i][j]
                else:
                    val = min(dp[i - 1][j], dp[i - 1][j - 1]) + t[i][j]
                if i == r - 1:
                    answer = min(answer, val)
                dp[i].append(val)
        return answer if r > 1 else t[0][0]
