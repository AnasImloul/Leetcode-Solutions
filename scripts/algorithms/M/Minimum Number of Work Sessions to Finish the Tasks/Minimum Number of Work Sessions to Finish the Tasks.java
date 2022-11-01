// Runtime: 116 ms (Top 47.58%) | Memory: 73.6 MB (Top 13.54%)
// Java Solution
class Solution {
    public int minSessions(int[] tasks, int sessionTime) {
        int n = tasks.length, MAX = Integer.MAX_VALUE;
        int[][] dp = new int[1<<n][2];
        dp[0][0] = 1;
        dp[0][1] = 0;

        for(int i = 1; i < (1 << n); i++) {
            dp[i][0] = MAX;
            dp[i][1] = 0;

            for(int t = 0; t < n; t++) {
                if(((1<<t) & i) == 0) continue;

                int[] prev = dp[(1<<t) ^ i];
                if(prev[1] + tasks[t] <= sessionTime) {
                    dp[i] = min(dp[i], new int[]{prev[0], prev[1] + tasks[t]});
                }else{
                    dp[i] = min(dp[i], new int[]{prev[0] + 1, tasks[t]});
                }
            }
        }

        return dp[(1<<n) - 1][0];
    }

    private int[] min(int[] d1, int[] d2) {
        if(d1[0] > d2[0]) return d2;
        if(d1[0] < d2[0]) return d1;
        if(d1[1] > d2[1]) return d2;

        return d1;
    }
}