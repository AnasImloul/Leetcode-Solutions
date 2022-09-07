// Runtime: 4 ms (Top 50.03%) | Memory: 44.5 MB (Top 32.12%)
class Solution {
    public int[] finalPrices(int[] prices) {
        for(int i = 0; i < prices.length; i++){
            for(int j = i + 1; j < prices.length; j++){
                if(j > i && prices[j] <= prices[i]){
                    prices[i] -= prices[j];
                    break;
                }
            }
        }
        return prices;
    }
}