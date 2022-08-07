class Solution {
    public int integerBreak(int n) {
        //dp array: maximum product of splitling int i
        int[] dp = new int[n + 1];
        
        // traverse
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                 dp[i] = Math.max(Math.max(j * (i - j), j * dp[i - j]), dp[i]);
            }
        }
        return dp[n];
    }
}
