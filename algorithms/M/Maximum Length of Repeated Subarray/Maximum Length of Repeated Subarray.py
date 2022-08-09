class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        dp = [[0]*(len(nums1)+ 1) for _ in range(len(nums2) + 1)]
        max_len = 0
        for row in range(len(nums2)):
            for col in range(len(nums1)):
                if nums2[row] == nums1[col]:
                    dp[row][col] = 1 + dp[row - 1][col - 1]
                    max_len = max(max_len,dp[row][col])
                else:
                    dp[row][col] = 0
        return max_len
    
