
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
