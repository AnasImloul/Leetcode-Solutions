class Solution:
    def minCost(self, maxTime: int, edges: List[List[int]], passingFees: List[int]) -> int:
        '''
        Time: O((m+n)* maxtime), where m is length of edges
        Space: O(n*maxtime)
        '''
        n = len(passingFees)
        dp = [[math.inf]*(n) for _ in range(maxTime+1)]
        dp[0][0] = passingFees[0]

        ans = math.inf
        for k in range(1, maxTime+1):
            for x, y, time in edges:
                if k >= time:
                    # dual direction
                    dp[k][y] = min(dp[k][y], dp[k-time][x] + passingFees[y])
                    dp[k][x] = min(dp[k][x], dp[k-time][y] + passingFees[x])
                
            ans = min(ans, dp[k][n-1])
        
        if ans == math.inf:
            return -1
        return ans
