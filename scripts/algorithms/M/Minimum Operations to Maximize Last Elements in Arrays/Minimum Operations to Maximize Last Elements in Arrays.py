# Runtime: 14 ms (Top 12.77%) | Memory: 19.60 MB (Top 36.17%)

class Solution:
    # Function to calculate the minimum number of operations to make two arrays non-decreasing.
    def minOperations(self, nums1, nums2):
        n = len(nums1)

        # dp[i][0]: Minimum operations if we make nums1[i:] and nums2[i:] non-decreasing.
        # dp[i][1]: Minimum operations if we swap nums1[i] and nums2[i] and then make nums1[i:] and nums2[i:] non-decreasing.
        dp = [[0, 1] for _ in range(n)]

        inf = 10**9

        # Dynamic Programming loop to fill in dp array.
        for i in range(n-2, -1, -1):
            dp[i][0] = dp[i][1] = inf

            # Case 1: If nums1[i] and nums2[i] can be included in the non-decreasing subsequence.
            if nums1[i] <= nums1[n-1] and nums2[i] <= nums2[n-1]:
                dp[i][0] = min(dp[i][0], dp[i+1][0])
                dp[i][1] = min(dp[i][1], dp[i+1][1] + 1)

            # Case 2: If nums1[i] and nums2[i] can be swapped and included in the non-decreasing subsequence.
            if nums1[i] <= nums2[n-1] and nums2[i] <= nums1[n-1]:
                dp[i][0] = min(dp[i][0], dp[i+1][0] + 1)
                dp[i][1] = min(dp[i][1], dp[i+1][1])

        # The best result is the minimum of operations needed to make both arrays non-decreasing from index 0.
        best = min(dp[0][0], dp[0][1])

        # If the best result is greater than n (the size of the arrays), it means it's not possible.
        if best > n:
            return -1

        # Return the minimum operations needed.
        return best
