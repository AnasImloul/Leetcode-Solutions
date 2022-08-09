class Solution {
    public int maxSizeSlices(int[] slices) {
        int n = slices.length;
        return Math.max(helper(slices, n/3, 0, n - 2), helper(slices, n/3, 1, n - 1));
    }
    
    private int helper(int[] slices, int rounds, int start, int end) {
        int n = end - start + 1, max = 0;
        int[][][] dp = new int[n][rounds+1][2];
        dp[0][1][1] = slices[start];
        for (int i = start + 1; i <= end; i++) {
            int x = i - start;
            for (int j = 1; j <= rounds; j++) {
                dp[x][j][0] = Math.max(dp[x-1][j][0], dp[x-1][j][1]);
                dp[x][j][1] = dp[x-1][j-1][0] + slices[i];
                if (j == rounds) {
                    max = Math.max(max, Math.max(dp[x][j][0], dp[x][j][1]));
                }
            }
        }
        return max;
    }
}
