class Solution {
    public int maxProfit(int[] prices) {
        
       int n = prices.length;
        int maxSellProfit = 0;
        int min = prices[0];
        int[] maxSellArr = new int[n];
        int i = 1;
        
        while(i < n){
            if(prices[i] < min){
                min = prices[i];
            }
            maxSellArr[i] = Math.max(maxSellArr[i-1],prices[i] - min);  
            
            i++;
        }
        int[] maxBuyArr = new int[n];
        int j = n-2;
        int max = prices[n-1];
        while(j >= 0){
            if(prices[j] > max){
                max = prices[j];
            }
            maxBuyArr[j] = Math.max(maxBuyArr[j+1],max - prices[j]);
            
            j--;
        }
        int maxProfitTwoTrans = 0;
        for(int k = 0; k < n; k++){
            maxProfitTwoTrans = Math.max(maxProfitTwoTrans,maxBuyArr[k] + maxSellArr[k]);
        }
        return maxProfitTwoTrans;
    }
}
