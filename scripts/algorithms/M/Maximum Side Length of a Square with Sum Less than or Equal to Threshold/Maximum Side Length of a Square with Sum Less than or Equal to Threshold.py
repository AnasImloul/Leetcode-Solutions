class Solution:
    def maxSideLength(self, mat: List[List[int]], threshold: int) -> int:
        # prefix matrix
        dp = [[0]*(len(mat[0])+1) for _ in range(len(mat)+1)]
        
        for i in range(1, len(mat)+1):
            for j in range(1, len(mat[0])+1):
                dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mat[i-1][j-1]
                       
        #bin search
        max_side = 0
        for i in range(1, len(mat) + 1):
            for j in range(1, len(mat[0]) + 1):
                if min(i, j) < max_side:
                    continue
                left = 0
                right = min(i,j)
                while left <= right:
                    mid = (left+right)//2
                    pref_sum = dp[i][j] - dp[i-mid][j] - dp[i][j-mid] + dp[i-mid][j-mid]
                    if pref_sum <= threshold:
                        max_side = max(max_side, mid)
                        left = mid + 1
                    else:
                        right = mid - 1
        return max_side
                    
