class Solution {
    public int profitableSchemes(int n, int minProfit, int[] group, int[] profit) {
        int M = (int)1e9+7, ans = 0;
        int[][] dp = new int[n+1][101];
        dp[0][0]=1;
        for (int i = 0; i < group.length; i++){
            int[][] next = new int[n+1][101];
            for (int j = 0; j <= n; j++){
                next[i]=dp[i].clone();
            }
            for (int j = 0; j <= 100; j++){
                for (int k = 0; k <= n-group[i]; k++){
                    next[k+group[i]][Math.min(100, j+profit[i])]+=dp[k][j];
                    next[k+group[i]][Math.min(100, j+profit[i])]%=M;
                }
            }
            dp=next;
        }
        for (int i = 0; i <= n; i++){
            for (int j = minProfit; j <= 100; j++){
                ans += dp[i][j];
                ans %= M;
            }
        }
        return ans;
    }
}
