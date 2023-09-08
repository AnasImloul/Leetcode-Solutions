// Runtime: 5 ms (Top 28.3%) | Memory: 45.04 MB (Top 8.2%)

class Solution {
    public int minRefuelStops(int target, int startFuel, int[][] stations) {
        if(startFuel >= target) return 0;
        int[][] dp = new int[stations.length + 1][stations.length + 1];
        for (int i = 0; i < dp.length; i++) dp[i][0] = startFuel;
        for (int j = 1; j < dp.length; j++) {
            for (int i = j; i < dp.length; i++) {
                dp[i][j] = Math.max(dp[i-1][j], stations[i-1][0] > dp[i-1][j-1] ?
                        Integer.MIN_VALUE : dp[i-1][j-1] + stations[i-1][1]);
                if(dp[i][j] >= target) return j;
            }
        }
        return -1;
    }
}