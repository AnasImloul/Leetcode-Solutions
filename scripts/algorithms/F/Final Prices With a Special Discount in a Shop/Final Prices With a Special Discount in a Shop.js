var finalPrices = function(prices) {
    let adjPrices = [];
    while(prices.length) {
        let currentPrice = prices[0];
        
        // Remove first price in original array
        // Since we're looking for a price less than or equal to
        prices.shift();
        
        let lowerPrice = prices.find((a) => a <= currentPrice);
        adjPrices.push(lowerPrice ? currentPrice - lowerPrice : currentPrice);
    }
    
    return adjPrices;
};
