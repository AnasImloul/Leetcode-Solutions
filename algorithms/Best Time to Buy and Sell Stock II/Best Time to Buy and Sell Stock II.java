class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length,profit = 0;
        for(int i=0;i<n-1;i++){
            if(prices[i+1]>prices[i]){
                profit += prices[i+1]-prices[i];
            }
        }
        return profit;
    }
}