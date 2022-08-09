class Solution {
    public double new21Game(int n, int k, int maxPts) {
        double[] dp = new double[k + maxPts];
        dp[0] = 1;
        for (int i = 0; i < k; i++){
            for (int j = 1; j <= maxPts; j++){
                dp[i + j] += dp[i] * 1.0 / maxPts;
            }
        }

        double ans = 0;
        for (int i = k; i < k + maxPts && i <= n; i++){
            ans += dp[i];
        }

        return ans;
    }
}
