class Solution:
    def minSideJumps(self, obstacles: List[int]) -> int:
        
        """
        # TLE Recursion DP
        @cache
        def dp(curr_lane = 2, point = 0):
            if point == len(obstacles)-1:
                return 0
            if obstacles[point+1] == curr_lane:
                return min(dp(lane, point+1) for lane in range(1, 4) if obstacles[point+1] != lane and obstacles[point]!=lane) + 1
            
            return dp(curr_lane, point+1)
        
        
        return dp()
            
        """
        
        n = len(obstacles)        
        dp = [[0, 0, 0, 0] for _ in range(n)]
        
        for point in range(n-2, -1, -1):
            for curr_lane in range(4):
                if obstacles[point+1] == curr_lane:
                    dp[point][curr_lane] = min(dp[point+1][lane] for lane in range(1, 4) if obstacles[point+1] != lane and obstacles[point]!=lane) + 1
                else:
                    dp[point][curr_lane] = dp[point+1][curr_lane]
                    
        return dp[0][2]