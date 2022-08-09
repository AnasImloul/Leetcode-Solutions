class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        from dataclasses import dataclass
        @dataclass
        class Cell:
            left: int = 0
            top: int = 0
            
        n = len(mat)
        m = len(mat[0])  
        dp = [[Cell() for _ in range(m + 1)] for _ in range(n + 1)]
        
        ans = 0
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if mat[i - 1][j - 1]: 
                    dp[i][j].top = 1 + dp[i - 1][j].top
                    dp[i][j].left = 1 + dp[i][j - 1].left
                    
                    min_height = dp[i][j].top
                    for k in range(dp[i][j].left):
                        min_height = min(min_height, dp[i][j-k].top)
                        ans += min_height 
        return ans
