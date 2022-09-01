// Runtime: 48 ms (Top 22.74%) | Memory: 58.7 MB (Top 87.06%)
class Solution {
    public int maxProfit(int[] prices, int fee) {
        int[][] dp = new int[prices.length][2];
        for (int[] a : dp) {
            a[0] = -1;
            a[1] = -1;
        }
        return profit(prices, fee, 0, 1, dp);
    }
    public int profit(int[] prices, int fee, int i, int buy, int[][] dp) {
        if (i == prices.length) {
            return 0;
        }
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        int maxProfit = 0;
        if (buy == 1) {
            int yesBuy = profit(prices, fee, i + 1, 0, dp) - prices[i];
            int noBuy = profit(prices, fee, i + 1, 1, dp);
            maxProfit = Math.max(yesBuy, noBuy);
        } else {
            int yesSell = prices[i] - fee + profit(prices, fee, i + 1, 1, dp);
            int noSell = profit(prices, fee, i + 1, 0, dp);
            maxProfit = Math.max(yesSell, noSell);
        }
        return dp[i][buy] = maxProfit;
    }
}