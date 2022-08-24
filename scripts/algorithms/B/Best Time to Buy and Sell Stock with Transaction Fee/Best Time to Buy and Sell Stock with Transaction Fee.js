// Runtime: 108 ms (Top 71.63%) | Memory: 49.5 MB (Top 46.05%)
/**
 * @param {number[]} prices
 * @param {number} fee
 * @return {number}
 */
var maxProfit = function(prices, fee) {
    let purchase = -1*prices[0];//If we purchase on 0th day
    let sell=0;//If we sell on 0th day
    let prevPurchase;
    for(let i=1;i<prices.length;i++){
        prevPurchase = purchase;
        purchase = Math.max(purchase,sell-prices[i]);//If we purchase on ith day
        sell = Math.max(sell,prevPurchase+prices[i]-fee);//If we sell on ith day
    }
    return sell;//If must return the best price whenever we sold stock because then only we can be at max profit.
};