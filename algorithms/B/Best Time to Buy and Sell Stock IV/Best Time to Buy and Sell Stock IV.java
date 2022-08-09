class Solution {
    public int maxProfit(int k, int[] prices) {
        int transaction = k;
        int N = prices.length;
        int[][][]dp =new int[N][2][k+1];
        for(int i=0;i<N;i++){
            for(int j =0;j<2;j++){
                for(int tran=0;tran<=k;tran++){
                    dp[i][j][tran] = -1;
                }
            }
        }//init dp
        return profit(0,1,k,prices,dp);
    }
    int profit(int index, int buy, int transaction , int[]prices, int[][][]dp){
        if(transaction == 0){
            return 0;
        }
        if(index == prices.length){
            return 0;
        }
        if(dp[index][buy][transaction] != -1){
            return dp[index][buy][transaction];
        }
        int profit =0;
        if(buy == 1){
            profit = Math.max(-prices[index] + profit(index+1,0,transaction,prices,dp),
                               0 + profit(index+1,1,transaction,prices,dp));
        }else{
            profit = Math.max(prices[index] + profit(index+1,1,transaction-1,prices,dp),
                              0 + profit(index+1, 0, transaction,prices,dp));
        }
        dp[index][buy][transaction] = profit;
        return dp[index][buy][transaction];
    }
}
