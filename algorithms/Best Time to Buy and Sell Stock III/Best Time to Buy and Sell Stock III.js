var maxProfit = function(prices) {
  if(prices.length == 0) return 0
  
  let dp = new Array(prices.length).fill(0);
  let min = prices[0];
  let max = 0;
  for (let i = 1; i < prices.length; i++) {
    min = Math.min(min, prices[i]);  // or Math.min(min, prices[i] - dp[i]) , FYI: dp[i] is 0
    max = Math.max(max, prices[i] - min);
    dp[i] = max;
  }
  
  // 1st run dp = [0,0,2,2,2,3,3,4];
  
  min = prices[0];
  max = 0;
  for (let i = 1; i < prices.length; i++) {
    min = Math.min(min, prices[i] - dp[i]); // substract dp[i]  = current price - what profit we made during 1st run.
    max = Math.max(max, prices[i] - min);
    dp[i] = max;
  }
  
  // 2nd run dp = [0,0,2,2,2,5,5,6];
  
  return dp.pop();
};
