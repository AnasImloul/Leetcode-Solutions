// Runtime: 2 ms (Top 55.13%) | Memory: 42.3 MB (Top 47.48%)
class Solution {
    public int maxProfit(int[] prices) {

        int n = prices.length;

        int[][] dp = new int[n+2][2];

        for(int index = n-1; index>=0; index--){
            for(int buy = 0; buy<=1; buy++){

                int profit = 0;

                if(buy == 0){ // buy stocks
                    profit = Math.max(-prices[index] + dp[index+1][1], 0 + dp[index+1][0]);
                }
                if(buy == 1){ // we can sell stocks
                    profit = Math.max(prices[index] + dp[index+2][0], 0 + dp[index+1][1]);
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][0];
    }
}