class Solution:
    
    def memoization(self, i, j, nums, dp):
        
        if i > j:
            return 0
        
        if dp[i][j] != -1:
            return dp[i][j]
        
        maxi = float('-inf')
        
        for ind in range(i, j+1):
            cost = nums[i-1] * nums[ind] * nums[j+1] + self.memoization(i, ind-1, nums, dp) + self.memoization(ind+1, j, nums, dp)
            maxi = max(maxi, cost)
            #dp[i][j] = maxi
        
        dp[i][j] = maxi
        return maxi
    
    def maxCoins(self, nums: List[int]) -> int:
        c = len(nums)
        nums.insert(0, 1)
        nums.append(1)
        n = len(nums)
        mem_dp = [[-1 for _ in range(c+1)] for _ in range(c+1)]
        
        #return self.memoization(1, c, nums, mem_dp)
        
        dp = [[0 for _ in range(c+2)] for _ in range(c+2)]
        
        for i in range(c, 0, -1):
            for j in range(1, c+1):
                if i > j:
                    continue
                maxi = float('-inf')
                for ind in range(i, j+1):
                    cost = nums[i-1] * nums[ind] * nums[j+1] + dp[i][ind-1] + dp[ind+1][j]
                    maxi = max(maxi, cost)
                    dp[i][j] = maxi
        
        return dp[1][c]