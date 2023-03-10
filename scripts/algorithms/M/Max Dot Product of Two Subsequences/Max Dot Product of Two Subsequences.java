class Solution {
    public int maxDotProduct(int[] nums1, int[] nums2) {
        int N = nums1.length, M = nums2.length;
        int[][] dp = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                dp[i][j] = nums1[i] * nums2[j];
                if (i > 0 && j > 0 && dp[i - 1][j - 1] > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                if (i > 0 && dp[i - 1][j] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j];
                }
                if (j > 0 && dp[i][j - 1] > dp[i][j]) {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[N - 1][M - 1];
    }
}