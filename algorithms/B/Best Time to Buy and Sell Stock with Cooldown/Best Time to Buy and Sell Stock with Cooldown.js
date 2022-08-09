/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let dp = {};
    let recursiveProfit = (index,buy) =>{
        if(index>=prices.length){
            return 0;
        }
        if(dp[index+'_'+buy]) return dp[index+'_'+buy]
        if(buy){
            dp[index+'_'+buy] = Math.max(-prices[index]+recursiveProfit(index+1,0), 0+recursiveProfit(index+1,1))
            return dp[index+'_'+buy];
        }
        else{
            dp[index+'_'+buy]= Math.max(prices[index]+recursiveProfit(index+2,1),0+recursiveProfit(index+1,0))
            return dp[index+'_'+buy];
        }
    }
    return recursiveProfit(0,1);
};
