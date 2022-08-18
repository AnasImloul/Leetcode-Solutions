// Runtime: 79 ms (Top 98.79%) | Memory: 51.8 MB (Top 55.26%)

var maxProfit = function(prices) {
    let L = 0;
    let result = 0;
    let length = prices.length;
    for( let R = 1 ;R < length; R++){
        if(prices[L] > prices[R]){
            L = R;
        }else {
                result = Math.max(result, prices[R] - prices[L]);

        }
    }
    return result;
};