// Runtime: 102 ms (Top 35.16%) | Memory: 42.5 MB (Top 44.08%)
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let lowestNum = prices[0];
    let highestNum = prices[0];
    let profit = highestNum - lowestNum;

    for(var indexI=1; indexI<prices.length; indexI++) {
      if(prices[indexI] < prices[indexI - 1]) {
          lowestNum = prices[indexI];
      }
      if(prices[indexI] > lowestNum) {
        lowestNum = prices[indexI - 1];
        profit = profit + prices[indexI] - lowestNum;
          highestNum = prices[indexI];
      }
    }

    return profit;
};