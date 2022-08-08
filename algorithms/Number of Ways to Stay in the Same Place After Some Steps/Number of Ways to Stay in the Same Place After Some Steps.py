class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        
        # obtain maximum index we can reach
        maxLen = min(steps+1, arrLen)
        dp = [0]*maxLen
        dp[0] = 1
        
        for step in range(1, steps+1):
            dp2 = [0]*maxLen
            for pos in range(maxLen):
                # dp[step][pos] = dp[step-1][pos] + dp[step-1][pos-1] + dp[step-1][pos+1] 
                temp1 = 0 if pos == 0 else dp[pos-1]
                temp2 = 0 if pos == maxLen-1 else dp[pos+1]
                dp2[pos] = (dp[pos] + temp1 + temp2)%(10**9+7)
                
            dp = dp2
        return dp[0]
