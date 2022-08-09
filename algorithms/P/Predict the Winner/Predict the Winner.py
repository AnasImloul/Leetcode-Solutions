class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        dp = [[-1] * len(nums) for _ in nums]
        def get_score(i: int, j: int) -> int:
            if i == j: 
                dp[i][j] = 0
                return dp[i][j]
            if i == j - 1:
                dp[i][j] = nums[j] if nums[i] > nums[j] else nums[i]
                return dp[i][j]
            if dp[i][j] != -1:
                return dp[i][j]

            y1 = get_score(i + 1, j - 1)
            y2 = get_score(i + 2, j)
            y3 = get_score(i, j - 2)
            res_y1 = y1 + nums[j] if y1 + nums[j] > y2 + nums[i+1] else y2 + nums[i+1]
            res_y2 = y1 + nums[i] if y1 + nums[i] > y3 + nums[j-1] else y3 + nums[j-1]

            dp[i][j] = min(res_y1, res_y2)
            return dp[i][j]       
                     
        y = get_score(0, len(nums) - 1)
        x = sum(nums) - y

        return 0 if y > x else 1
