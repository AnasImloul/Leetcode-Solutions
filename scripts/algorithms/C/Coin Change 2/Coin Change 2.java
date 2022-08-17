class Solution {
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        // for each coin iteration : dp[i] = number of coins required to make i with coins [0...coin]
        dp[0] = 1;
        for(int coin : coins) {
            for(int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
}
